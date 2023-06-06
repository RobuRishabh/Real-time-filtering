#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include "filter.h"

using namespace std;
using namespace cv;

int main(int argc, char* argv[]){
    cout<<"starting...."<<endl;
    cout << "Hello User" << endl;
        cout << "Please choose from these options:\n"
        "1. Press 'g' = grayscale\n"
        "2. Press 'h' = alternate grayscale\n"
        "3. Press 'b' = Gaussian blur\n"
        "4. Press 'x' = SobelX\n"
        "5. Press 'y' = SobelY\n"
        "6. Press 'm' = Gradient magnitude\n"
        "7. Press 'i' = Quantize\n"
        "8. Press 'c' = cartoonization\n"
        "9. Press 'p' = Sparkles\n"
        "10. Press 'n' = negative\n"
        "11. Press 'w' = warm or sepia\n"
        "12. Press 'f' = flip the picture\n"
        "13. Press 's' = save the image\n"
        "14. Press 'q' = quit\n" << endl;
    // Declares a pointer capdev of type cv::VideoCapture, which will be used to access the video device.
    cv::VideoCapture* capdev;
    //Creates a new instance of cv::VideoCapture and assigns it to the pointer capdev. 
    //The parameter 0 indicates that the program will capture video from the default camera device.
    capdev = new cv::VideoCapture(2);
    if(!capdev -> isOpened()) {
        cout<<"Unable to open video Device\n"<<endl;
        return -1;
    }

    //get some properties of the image
    cv:: Size refS((int)capdev -> get(cv::CAP_PROP_FRAME_WIDTH), (int)capdev -> get(cv::CAP_PROP_FRAME_HEIGHT));
    cout<<"Expected size: %d %d\n", refS.width, refS.height;

    //identifies a window
    cv::namedWindow("Output Window", cv::WINDOW_AUTOSIZE);
    cv::resizeWindow("Output Window", 20, 15);


    //Declare a cv::Mat object named frame, used to store the captured video frame.
    cv::Mat frame;

    for( ; ; ){
        //get a new frame from the camera, treat as a stream
        *capdev >> frame; 
        if(frame.empty()){
            cout<<"This frame is empty"<<endl;
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
        static bool nPressed = false;
        static bool wPressed = false;

        bool anyKeyPressed = false;
        bool sPressed = false;

        //waits for a key press for 30 milliseconds
        char key = cv::waitKey(30);
        if(key == 'q'){
            cout<<"q is pressed"<<endl;
            break;
        }
        if(key == 's'){
            imwrite("Output_image.jpg", frame);
            cout<<"Image is saved"<<endl;
            sPressed = true;
        }
        if(key == 'g'){
            cout<<"g is pressed"<<endl;
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
            nPressed = false;
            wPressed = false;

        }
        if(key == 'h'){
            cout<<"h is pressed"<<endl;
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
            nPressed = false;
            wPressed = false;

        }
        if(key == 'b'){
            cout<<"b is pressed"<<endl;
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
            nPressed = false;
            wPressed = false;

        }
        if(key == 'x'){
            cout<<"x is pressed"<<endl;
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
            nPressed = false;
            wPressed = false;

        }
        if(key == 'y'){
            cout<<"y is pressed"<<endl;
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
            nPressed = false;
            wPressed = false;

        }
        if(key == 'm'){
            cout<<"m is pressed"<<endl;
            gPressed = true;
            hPressed = false;
            bPressed = false;
            xPressed = false;
            yPressed = false;
            mPressed = true;
            iPressed = false;
            cPressed = false;
            pPressed = false;
            fPressed = false;
            nPressed = false;
            wPressed = false;

        }
        if(key == 'i'){
            cout<<"i is pressed"<<endl;
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
            nPressed = false;
            wPressed = false;

        }
        if(key == 'c'){
            cout<<"c is pressed"<<endl;
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
            nPressed = false;
            wPressed = false;

        }
        if(key == 'p'){
            cout<<"p is pressed"<<endl;
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
            nPressed = false;
            wPressed = false;

        }
        if(key == 'f'){
            cout<<"f is pressed"<<endl;
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
            nPressed = false;
            wPressed = false;
        }
        if(key == 'n'){
            cout<<"n is pressed"<<endl;
            gPressed = false;
            hPressed = false;
            bPressed = false;
            xPressed = false;
            yPressed = false;
            mPressed = false;
            iPressed = false;
            cPressed = false;
            pPressed = false;
            fPressed = false;
            nPressed = true;
            wPressed = false;
        }
        if(key == 'w'){
            cout<<"w is pressed"<<endl;
            gPressed = false;
            hPressed = false;
            bPressed = false;
            xPressed = false;
            yPressed = false;
            mPressed = false;
            iPressed = false;
            cPressed = false;
            pPressed = false;
            fPressed = false;
            nPressed = false;
            wPressed = true;
        }
        if(gPressed){
            //Convert to grayscale
            anyKeyPressed = true;
            //Converts the frame from color to grayscale using the cv::cvtColor() function
            //The resulting grayscale frame is stored back into the frame variable.
            cv::cvtColor(frame, frame, cv::COLOR_BGR2GRAY);
            cv::imshow("Output Video", frame);
            if(sPressed){
                cv::imwrite("Original_Grayscale.png", frame);
            }
        }
        if(hPressed){
            //Converts the frame from color to grayscale using the grayscale function
            //The resulting grayscale frame is stored back into the frame variable.
            anyKeyPressed = true;
            grayscale(frame, frame);
            cv::imshow("Output Video", frame);
            if(sPressed){
                cv::imwrite("Alternate_Grayscale.png", frame);
            }

        }
        if(bPressed){
            //Gaussian Blur filter
            anyKeyPressed = true;
            blur5x5(frame, frame);
            cv::imshow("Output Video", frame);
            if(sPressed){
                cv::imwrite("blur.png", frame);
            }
        }
        // Does not allocate new data in sobelFrameX
        //sobelFrameX just references frame data without allocating new memory
        cv::Mat sobelFrameX = frame;
        if(xPressed){
            //SobelX filter
            anyKeyPressed = true;
            sobelX3x3(frame, sobelFrameX);
            //The cv::convertScaleAbs() function is used to convert the filtered 
            //sobelFrameX to an absolute representation and scale it by a factor of 2.
            cv::convertScaleAbs(sobelFrameX, sobelFrameX, 2);
            cv::imshow("Output Video", sobelFrameX);
            if(sPressed){
                cv::imwrite("SobelX.png", sobelFrameX);
            }
        }
        // Does not allocate new data in sobelFrameY, sobelFrameY just references frame data.
        cv::Mat sobelFrameY = frame;
        if(yPressed){
            //SobelY filter
            anyKeyPressed = true;
            sobelY3x3(frame, sobelFrameY);
            cv::convertScaleAbs(sobelFrameY, sobelFrameY, 4);
            cv::imshow("Output Video", sobelFrameY);
            if(sPressed){
                cv::imwrite("SobelY.png", sobelFrameY);
            }
        }
        if (mPressed) {
            anyKeyPressed = true;
            cv::Mat gradientMag, sobelx, sobely;
            sobelX3x3(frame, sobelx);
            sobelY3x3(frame, sobely);
            magnitude(sobelx, sobely, gradientMag);
            cv::convertScaleAbs(gradientMag, gradientMag, 4);
            cv::imshow("Output Video", gradientMag);
            if (sPressed)
                cv::imwrite("magnitude.png", gradientMag);
        }
        if (iPressed) {
            anyKeyPressed = true;
            cv::Mat dst = frame;
            blurQuantize(frame, dst, 15);
            cv::imshow("Output Video", dst);
            if (sPressed)
                cv::imwrite("gradient.png", dst);
        }
        if (cPressed) {
            anyKeyPressed = true;
            cv::Mat cartoonized = frame;
            cartoon(frame, cartoonized, 15, 20);
            cv::imshow("Output Video", cartoonized);
            if (sPressed)
                cv::imwrite("cartoon.png", cartoonized);
        }
        if (nPressed){
            anyKeyPressed = true;
            cv::Mat dst = frame;
            negative(frame, dst);
            cv::imshow("Output Video", dst);
            if(sPressed)
                cv::imwrite("negative.png", dst);
        }
        if (wPressed){
            anyKeyPressed = true;
            cv::Mat dst = frame;
            sepia(frame, dst);
            cv::imshow("Output Video", dst);
            if(sPressed)
                cv::imwrite("sepia.png", dst);
        }

        if (pPressed) {
            anyKeyPressed = true;
            cv::Mat sparkles = frame;
            Sparkles(frame, sparkles, 20);
            cv::imshow("Output Video", sparkles);
            if (sPressed)
                cv::imwrite("sparkles.png", sparkles);
        }
        if (fPressed) {
            anyKeyPressed = true;
            cv::Mat Flip_z;
            flip(frame, Flip_z, -1);
            cv::imshow("Output Video", Flip_z);
            if (sPressed){
                cv::imwrite("flipz.png", Flip_z);
            }
        }
    }
    delete capdev;
    return(0);
}