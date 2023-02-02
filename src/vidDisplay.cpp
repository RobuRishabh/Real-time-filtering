#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include "filter.h"

using namespace std;


int main(int argc, char* argv[]) {
    printf("starting...");
    cv::VideoCapture* capdev;
    // open the video device
    capdev = new cv::VideoCapture(0);
    if (!capdev->isOpened()) {
        printf("Unable to open video device\n");
        return(-1);
    }

    // get some properties of the image
    cv::Size refS((int)capdev->get(cv::CAP_PROP_FRAME_WIDTH),
        (int)capdev->get(cv::CAP_PROP_FRAME_HEIGHT));
    printf("Expected size: %d %d\n", refS.width, refS.height);

    cv::namedWindow("Video", 1); // identifies a window


    cv::Mat frame;

    for (;;) {
        *capdev >> frame; // get a new frame from the camera, treat as a stream
        if (frame.empty()) {
            printf("frame is empty\n");
            break;
        }
       
        static bool gPressed = false;
        static bool hPressed = false;
        static bool bPressed = false;
        static bool xPressed = false;
        static bool yPressed = false;
        static bool mPressed = false;
        static bool iPressed = false;
        static bool cPressed = false;
        static bool pPressed = false;
        static bool fPressed = false;
        bool anyKeyPressed = false;
        bool sPressed = false;
        

        // see if there is a waiting keystroke
        char key = cv::waitKey(30);
        if (key == 'q') {
            cout << "q pressed" << endl;
            break;
        }
        if (key == 's') {
            imwrite("image.jpg", frame);
            cout << "Image saved" << endl;
            sPressed = true;
        }
        if (key == 'g') {
            cout << "g pressed" << endl;
            gPressed = true;
            hPressed = false;
            bPressed = false;
            xPressed = false;
            yPressed = false;
            mPressed = false;
            iPressed = false;
            cPressed = false;
            pPressed = false;
            fPressed = false;
        }
        if (key == 'h') {
            cout << "h pressed" << endl;
            gPressed = false;
            hPressed = true;
            bPressed = false;
            xPressed = false;
            yPressed = false;
            mPressed = false;
            iPressed = false;
            cPressed = false;
            pPressed = false;
            fPressed = false;
        }
        if (key == 'b') {
            cout << "b pressed" << endl;
            gPressed = false;
            hPressed = false;
            bPressed = true;
            xPressed = false;
            yPressed = false;
            mPressed = false;
            iPressed = false;
            cPressed = false;
            pPressed = false;
            fPressed = false;
        }
        if (key == 'x') {
            cout << "x pressed" << endl;
            gPressed = false;
            hPressed = false;
            bPressed = false;
            xPressed = true;
            yPressed = false;
            mPressed = false;
            iPressed = false;
            cPressed = false;
            pPressed = false;
            fPressed = false;
        }
        if (key == 'y') {
            cout << "y pressed" << endl;
            gPressed = false;
            hPressed = false;
            bPressed = false;
            xPressed = false;
            yPressed = true;
            mPressed = false;
            iPressed = false;
            cPressed = false;
            pPressed = false;
            fPressed = false;
        }

        if (key == 'm') {
            cout << "m pressed" << endl;
            gPressed = false;
            hPressed = false;
            bPressed = false;
            xPressed = false;
            yPressed = false;
            mPressed = true;
            iPressed = false;
            cPressed = false;
            pPressed = false;
            fPressed = false;
        }

        if (key == 'i') {
            cout << "i pressed" << endl;
            gPressed = false;
            hPressed = false;
            bPressed = false;
            xPressed = false;
            yPressed = false;
            mPressed = false;
            iPressed = true;
            cPressed = false;
            pPressed = false;
            fPressed = false;

        }

        if (key == 'c') {
            cout << "c pressed" << endl;
            gPressed = false;
            hPressed = false;
            bPressed = false;
            xPressed = false;
            yPressed = false;
            mPressed = false;
            iPressed = false;
            cPressed = true;
            pPressed = false;
            fPressed = false;
        }

        if (key == 'p') {
            cout << "p pressed" << endl;
            gPressed = false;
            hPressed = false;
            bPressed = false;
            xPressed = false;
            yPressed = false;
            mPressed = false;
            iPressed = false;
            cPressed = false;
            pPressed = true;
            fPressed = false;
        }

        if (key == 'f') {
            cout << "f pressed" << endl;
            gPressed = false;
            hPressed = false;
            bPressed = false;
            xPressed = false;
            yPressed = false;
            mPressed = false;
            iPressed = false;
            cPressed = false;
            pPressed = false;
            fPressed = true;
        }
        if (gPressed)
        {
            // Convert frame to greyscale
            cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
            if (sPressed)
                cv::imwrite("grey.png", frame);
        }

        if (hPressed) {
            // Convert frame to greyscale using an alternative method
            anyKeyPressed = true;
            greyscale(frame, frame);
            cv::imshow("Video", frame);
            if (sPressed)
                cv::imwrite("alt_grey.png", frame);
        }
        if (bPressed) {
            anyKeyPressed = true;
            blur5x5(frame, frame);
            cv::imshow("Video", frame);
            if (sPressed)
                cv::imwrite("blur.png", frame);
        }
        cv::Mat sobelFrameX = frame;
        if (xPressed) {
            anyKeyPressed = true;
            sobelX3x3(frame, sobelFrameX);
            cv::convertScaleAbs(sobelFrameX, sobelFrameX, 2);
            cv::imshow("Video", sobelFrameX);
            if (sPressed)
                cv::imwrite("sobelX.png", sobelFrameX);
        }
        cv::Mat sobelFrameY = frame;
        if (yPressed) {
            anyKeyPressed = true;
            sobelY3x3(frame, sobelFrameY); 
            cv::convertScaleAbs(sobelFrameY, sobelFrameY, 4);
            cv::imshow("Video", sobelFrameY);
            if (sPressed)
                cv::imwrite("sobelY.png", sobelFrameY);
        }
        if (mPressed) {
            anyKeyPressed = true;
            cv::Mat gradientMag, sobelx, sobely;
            sobelX3x3(frame, sobelx);
            sobelY3x3(frame, sobely);
            magnitude(sobelx, sobely, gradientMag);
            cv::convertScaleAbs(gradientMag, gradientMag, 4);
            cv::imshow("Video", gradientMag);
            if (sPressed)
                cv::imwrite("magnitude.png", gradientMag);
        }
        if (iPressed) {
            anyKeyPressed = true;
            cv::Mat dst = frame;
            blurQuantize(frame, dst, 15);
            cv::imshow("Video", dst);
            if (sPressed)
                cv::imwrite("gradient.png", dst);
        }
        if (cPressed) {
            anyKeyPressed = true;
            cv::Mat cartoonized = frame;
            cartoon(frame, cartoonized, 15, 20);
            cv::imshow("Video", cartoonized);
            if (sPressed)
                cv::imwrite("cartoon.png", cartoonized);
        }
        if (pPressed) {
            anyKeyPressed = true;
            cv::Mat sparkles = frame;
            Sparkles(frame, sparkles, 20);
            cv::imshow("Video", sparkles);
            if (sPressed)
                cv::imwrite("sparkles.png", sparkles);
        }
        if (fPressed) {
            anyKeyPressed = true;
            cv::Mat img2, img3, img4;

           cv::imshow("Video", frame);

            cv::flip(frame, img2, 0);
            applyColorMap(frame, img2, 0);
            cv::namedWindow("Flip-x-axis", cv::WINDOW_AUTOSIZE);
            cv::imshow("Flip-x-axis", img2);

            
            flip(frame, img3, -1);
            cv::namedWindow("Flip-z-axis", cv::WINDOW_AUTOSIZE);
            cv::imshow("Flip-z-axis", img3);

            if (sPressed)
                cv::imwrite("flipx.png", img2);
                cv::imwrite("flipz.png", img3);
       
        }
        if (!anyKeyPressed)
            cv::imshow("Video", frame);

    }

    delete capdev;
    return(0);
}