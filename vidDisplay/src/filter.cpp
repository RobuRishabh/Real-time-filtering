#include "filter.h"

int grayscale(cv::Mat& src, cv::Mat& dst){
    //convert src to grayscale using alternative method
    cv::cvtColor(src, dst, cv::COLOR_BGR2HSV);
    vector<cv::Mat> HSV(3);
    split(dst, HSV);
    //Extracting V-channel
    dst = HSV[2];
    return 0;
}

int blur5x5(cv::Mat& src, cv::Mat& dst) {
    //copies the contents of the src image to the dst image.
    //This ensures that dst has the same size and type as src.
    src.copyTo(dst);
    
    cv::Mat temp;
    //copies the contents of the src image to temp.
    //This creates a separate copy of the src image.
    src.copyTo(temp);

    //An integer variable value is declared and initialized to 0.
    //This variable will be used to store the calculated weights.    
    int value = 0;
    //iterate over each pixel in the src image.
    //The outer loop iterates over the rows (i)
    //the inner loop iterates over the columns (j).
    //starts the horizontal blurring pass.
    for (int i = 0; i < src.rows; ++i) {
        for (int j = 0; j < src.cols; ++j) {
            //A cv::Vec3b object called result is created.
            //This object represents a 3-channel vector for storing the resulting pixel values after blurring.
            cv::Vec3b result;
            //iterate over the color channels (B, G, R) of the pixel.
            for (int k = 0; k < 3; ++k) {
                //A variable sum will be used to accumulate the weighted sum of pixel values
                //based on the kernel weights and neighboring pixels.
                float sum = 0;
                //loop is used to iterate over a 5x5 kernel centered around the current pixel (i, j).
                for (int m = -2; m <= 2; ++m) {
                    //Depending on the value of m, different weights are assigned to value.
                    if (i + m >= 0 && i + m < src.rows) {
                        
                        if (m == -2 || m == 2) {
                            value = 1;
                        }
                        else if (m == -1 || m == 1) {
                            value = 2;
                        }
                        else {
                            value = 4;
                        }
                        //pixel value at the (i + m, j) position is accessed from the src image 
                        //using src.at<cv::Vec3b>(i + m, j)[k]. The value is multiplied by the corresponding weight value and added to the sum.
                        sum += src.at<cv::Vec3b>(i + m, j)[k] * value;
                    }
                }
                //accumulated sum is divided by 10 (the sum of the weights) to compute the average pixel value.
                //resulting value is cast to uchar and assigned to the result vector at the k channel.
                result[k] = (uchar)(sum / 10);
            }
            //blurred pixel values in the result vector are stored in the temporary image t at the corresponding position (i, j).
            temp.at<cv::Vec3b>(i, j) = result;
        }
        
    }
    
    //Two nested for loops iterate over each pixel in the src image again.
    //This time, it starts the vertical blurring pass.
    for (int i = 0; i < src.rows; ++i) {
        for (int j = 0; j < src.cols; ++j) {
            cv::Vec3b result;
            for (int k = 0; k < 3; ++k) {
                float sum = 0;
                for (int m = -2; m <= 2; ++m) {
                    if (j + m >= 0 && j + m < src.cols) {
                        
                        if (m == -2 || m == 2) {
                            value = 1;
                        }
                        else if (m == -1 || m == 1) {
                            value = 2;
                        }
                        else {
                            value = 4;
                        }
                        sum += temp.at<cv::Vec3b>(i, j + m)[k] * value;
                    }
                }
                result[k] = (uchar)(sum / 10);
            }
            //The blurred pixel values in the result vector are stored in the dst image at the corresponding position (i, j).
            dst.at<cv::Vec3b>(i, j) = result;
        }
    }
    
    return 0;
}

int sobelX3x3(cv::Mat& src, cv::Mat& dst) {
    dst = cv::Mat(src.size(), CV_16S);
    for (int i = 1; i < src.rows - 1; ++i) {
        for (int j = 1; j < src.cols - 1; ++j) {
            // 3x3 Sobel_X filter
            int sobelX[3][3] = { {-1, 0, 1},
                                 {-2, 0, 2},
                                 {-1, 0, 1} };
            // more dark, less dark, bright
            int sum_X = 0;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    int valueAtPx = src.at<cv::Vec3b>(i + x, j + y)[0];
                    int valueAtKernel = sobelX[x + 1][y + 1];
                    sum_X += valueAtPx * valueAtKernel;
                }
            }
            dst.at<short>(i, j) = sum_X;
        }
    }
    return 0;
}

int sobelY3x3(cv::Mat& src, cv::Mat& dst) {
    dst = cv::Mat(src.size(), CV_16S);

    for (int i = 1; i < src.rows - 1; ++i) {
        for (int j = 1; j < src.cols - 1; ++j) {
            // 3x3 Sobel_Y filter
            int sobelY[3][3] = { {-1, -2, -1},
                                  {0, 0, 0},
                                  {1, 2, 1} };
            int sum_Y = 0;
            for (int x = -1; x <= 1; ++x) {
                for (int y = -1; y <= 1; ++y) {
                    int valueAtPx = src.at<cv::Vec3b>(i + x, j + y)[0];
                    int valueAtKernel = sobelY[x + 1][y + 1];
                    sum_Y += valueAtPx * valueAtKernel;
                }
            }

            dst.at<short>(i, j) = sum_Y;
        }
    }
    return 0;
}

int magnitude(cv::Mat& sx, cv::Mat& sy, cv::Mat& dst){
    dst = cv::Mat(sx.size(), CV_8UC3); //8bit uchar 3-channel image
    for (int i = 0; i < sx.rows; ++i) {
        for (int j = 0; j < sx.cols; ++j) {
            // Gradient magnitude image using Euclidean distance for magnitude: 
            // I = sqrt(sx*sx + sy*sy)
            int slx = sx.at<short>(i, j);
            int sly = sx.at<short>(i, j);
            int magnitude = sqrt(slx * slx + sly * sly);         
            magnitude = min(255, max(magnitude, 0));                 //Normalization
            dst.at<cv::Vec3b>(i, j) = cv::Vec3b(magnitude, magnitude, magnitude);
        }
    }
    return 0;
}

int blurQuantize(cv::Mat& src, cv::Mat& dst, int levels){
    blur5x5(src, dst);
    //calculates the quantization step size by dividing the maximum value (255) by the desired number of quantization levels (levels).
    int b = 255 / levels;
    //This line starts a loop over the rows of the dst image.
    for(int i=0; i<src.rows; i++){ 
        //This line starts a nested loop over the columns of the dst image.
        for(int j=0; j<src.cols; j++){
            for (int k = 0; k < 3; ++k) {
                int value = src.at<cv::Vec3b>(i, j)[k];
                int quantizedVal = (value / b) * b;
                src.at<cv::Vec3b>(i, j)[k] = quantizedVal;
            }
        }
    }
    dst = src;
    return 0;
}

int cartoon(cv::Mat& src, cv::Mat& dst, int levels, int magThreshold){
    //declares a cv::Mat object named sx_result with the same size as the input image src and type CV_16SC3 (16-bit signed integers with 3 channels).
    //It will be used to store the result of the horizontal Sobel operator.
    cv::Mat sx_result(src.rows, src.cols, CV_16SC3);
    //perform the horizontal Sobel operation on the input image src and store the result in sx_result. 
    sobelX3x3(src, sx_result);
    //declares a cv::Mat object named y_sobel_result with the same size as the input image src and type CV_16SC3.
    //It will be used to store the result of the vertical Sobel operator.
    cv::Mat sy_result(src.rows, src.cols, CV_16SC3);
    //perform the vertical Sobel operation on the input image src and store the result in y_sobel_result.
    sobelY3x3(src, sy_result);
    //declares a cv::Mat object named magnitude_result with the same size as the input image src and type CV_8UC3 (8-bit unsigned integers with 3 channels).
    //It will be used to store the magnitude of the gradient computed from the sx_result and sy_result.
    cv::Mat magnitude_result(src.rows, src.cols,CV_8UC3);
    //compute the magnitude of the gradient using the x_sobel_result and y_sobel_result images and store the result in magnitude_result.
    magnitude(sx_result, sy_result, magnitude_result);
    //blurQuantize to apply blur filtering and quantization on the input image src and store the result in dst.
    //The levels parameter is passed to specify the desired number of quantization levels.
    blurQuantize(src,dst, levels);
    //iterate over each pixel of the dst image
    for(int i=0; i<dst.rows; i++){
        for(int j=0; j<dst.cols; j++){
            for(int k=0; k<3; k++){
                //checks if the magnitude value of the corresponding pixel in magnitude_result is greater than the specified magThreshold.
                if(magnitude_result.at<cv::Vec3b>(i, j)[k] > magThreshold){
                    //If the magnitude value exceeds the threshold, the pixel value in the dst image is set to 0 for the corresponding channel.
                    dst.at<cv::Vec3b>(i, j)[k] = 0;
                }
            }
        }
    }
    return 0;
}

int negative(cv::Mat& src, cv::Mat& dst){
    //iterate over each pixel of the dst image
    for(int i=0; i<dst.rows; i++){
        for(int j=0; j<dst.cols; j++){
            //calculates the negative value for each channel of the pixel in the src image at position (i, j). 
            //It subtracts each channel value from 255 and assigns the result to the corresponding channel of the pixel in the dst image.
            dst.at<cv::Vec3b>(i, j) = cv::Vec3b(255 - src.at<cv::Vec3b>(i, j)[0],
                                                255 - src.at<cv::Vec3b>(i, j)[1],
                                                255 - src.at<cv::Vec3b>(i, j)[2]);
        }
    }
    return 0;
}

int sepia(cv::Mat& src, cv::Mat& dst){
    //iterate over each pixel of the src image
    for(int i=0; i<src.rows; i++){
        for(int j=0; j<src.cols; j++){
            //declares three variables to store the accumulated values of the blue, green, and red channels, respectively, for each pixel.
            double b_sum, g_sum, r_sum;
            //The next three lines calculate the new values for the bgr channels of the pixel at (i, j) in the src image using the following formulas:
            // int tr = (int)(0.393*r + 0.769*g + 0.189*b);
            b_sum = src.at<cv::Vec3b>(i,j)[2] * 0.272 + src.at<cv::Vec3b>(i,j)[1] * 0.534 + src.at<cv::Vec3b>(i,j)[0] * 0.131;
            g_sum = src.at<cv::Vec3b>(i,j)[2] * 0.349 + src.at<cv::Vec3b>(i,j)[1] * 0.686 + src.at<cv::Vec3b>(i,j)[0] * 0.168;
            r_sum = src.at<cv::Vec3b>(i,j)[2] * 0.393 + src.at<cv::Vec3b>(i,j)[1] * 0.769 + src.at<cv::Vec3b>(i,j)[0] * 0.189;
            //The next 3 lines clamp the calculated values of b_sum, g_sum, and r_sum to a maximum value of 255 using the fmin function.
            //This ensures that the channel values stay within the valid range of 0 to 255.
            b_sum = fmin(255, b_sum);
            g_sum = fmin(255, g_sum);
            r_sum = fmin(255, r_sum);
            dst.at<cv::Vec3b>(i,j) = cv::Vec3b(b_sum, g_sum, r_sum);
         }
    }
    return 0;
}

//Sparkles function takes the input src, the output dst, and the magnitude threshold for the Canny edge detection algorithm as parameters.
int Sparkles(cv::Mat& src, cv::Mat& dst, int magThreshold){
    //declares a new cv::Mat variable called det_edge, which will be used to store the edge detection result.
    cv::Mat det_edge;
    /*
    Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*ratio, kernel_size );
    where the arguments are:
    detected_edges: Source image, grayscale
    detected_edges: Output of the detector (can be the same as the input)
    lowThreshold: The value entered by the user moving the Trackbar
    highThreshold: Set in the program as three times the lower threshold (following Canny's recommendation)
    */

    cv::Canny(src, det_edge, magThreshold, magThreshold*2);
    //iterate over each pixel of the det_edge image
    for(int i=0; i<det_edge.rows; i++){
        for(int j=0; j<det_edge.cols; j++){
            //checks if the pixel at position (i, j) in the det_edge image is an edge pixel.
            //The threshold value of 255 indicates that it is an edge pixel.
            if(det_edge.at<uchar>(i,j) == 255){
                //sets the blue channel of the pixel at position (i, j) in the dst image to 255
                //indicating a blue color for the highlight.
                dst.at<cv::Vec3b>(i,j)[0] = 255;
                //sets the green channel of the pixel at position (i, j) in the dst image to 255
                //indicating a green color for the highlight.
                dst.at<cv::Vec3b>(i,j)[1] = 255;
                //sets the red channel of the pixel at position (i, j) in the dst image to 0
                //indicating no red color for the highlight.
                dst.at<cv::Vec3b>(i,j)[2] = 0;
            }
        }
    }
    return 0;
}


