#include "filter.h"

int greyscale(cv::Mat& src, cv::Mat& dst) {
    // Convert src to greyscale using an alternative method,
    cv::cvtColor(src, dst, cv::COLOR_BGR2HSV);
    vector<cv::Mat> hsv(3);
    split(dst, hsv);
    // Extracting V-channel
    dst = hsv[2];
    return 0;
}

int blur5x5(const cv::Mat& src, cv::Mat& dst) {
    src.copyTo(dst);
    
    cv::Mat t;
    src.copyTo(t);
    
    int value = 0;
    for (int i = 0; i < src.rows; ++i) {
        for (int j = 0; j < src.cols; ++j) {
            cv::Vec3b result;
            for (int k = 0; k < 3; ++k) {
                float sum = 0;
                for (int m = -2; m <= 2; ++m) {
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
                        
                        sum += src.at<cv::Vec3b>(i + m, j)[k] * value;
                    }
                }
                result[k] = (uchar)(sum / 10);
            }
            t.at<cv::Vec3b>(i, j) = result;
        }
        
    }
    
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
                        sum += t.at<cv::Vec3b>(i, j + m)[k] * value;
                    }
                }
                result[k] = (uchar)(sum / 10);
            }
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

int magnitude(const cv::Mat& sx, const cv::Mat& sy, cv::Mat& dst){
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

int blurQuantize(cv::Mat& src, cv::Mat& dst, int levels) {
    cv::GaussianBlur(src, src, cv::Size(5, 5), 0);
    int b = 255 / levels;
    for (int i = 0; i < src.rows; ++i) {
        for (int j = 0; j < src.cols; ++j) {
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

int cartoon(cv::Mat& src, cv::Mat& dst, int levels, int magThreshold) {
    cv::Mat magMagnitude, sobelx, sobely;
    sobelX3x3(src, sobelx);
    sobelY3x3(src, sobely);
    magnitude(sobelx, sobely, magMagnitude);
    cv::Mat blurMat;
    blurQuantize(src, blurMat, levels);
    for (int i = 0; i < src.rows; ++i) {
        for (int j = 0; j < src.cols; ++j) {
            if (magMagnitude.at<uchar>(i, j) > magThreshold) {
                blurMat.at<cv::Vec3b>(i, j) = cv::Vec3b(0, 0, 0);
            }
        }
    }
    dst = blurMat;
    return 0;
}

int Sparkles(const cv::Mat& src, cv::Mat& dst, int magThreshold) {
    cv::Mat det_edge;
    cv::Canny(src, det_edge, magThreshold, magThreshold * 2);
    for (int i = 0; i < det_edge.rows; ++i) {
        for (int j = 0; j < det_edge.cols; ++j) {
            if (det_edge.at<uchar>(i, j) == 255) {
                dst.at<cv::Vec3b>(i, j)[0] = 255;
                dst.at<cv::Vec3b>(i, j)[1] = 255;
                dst.at<cv::Vec3b>(i, j)[2] = 0;
            }
        }
    }
    return 0;
}











