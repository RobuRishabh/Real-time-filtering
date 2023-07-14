#pragma once

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace std;

int grayscale(cv::Mat& src, cv::Mat& dst);
int blur5x5( cv::Mat& src, cv::Mat& dst);
int sobelX3x3(cv::Mat& src, cv::Mat& dst);
int sobelY3x3(cv::Mat& src, cv::Mat& dst);
int magnitude(cv::Mat& sx, cv::Mat& sy, cv::Mat& dst);
int blurQuantize(cv::Mat& src, cv::Mat& dst, int levels);
int cartoon(cv::Mat& src, cv::Mat& dst, int levels, int magThreshold);
int negative(cv::Mat& src, cv::Mat& dst);
int sepia(cv::Mat& src, cv::Mat& dst);
int Sparkles(cv::Mat& src, cv::Mat& dst, int magThreshold);