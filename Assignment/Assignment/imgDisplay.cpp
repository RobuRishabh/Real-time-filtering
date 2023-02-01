#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
using namespace std;

int main2()
{
	cv::Mat img = cv::imread(R"(C:\Users\rsluc\source\repos\OpenCV_Project1\OpenCV_Project1\starry_nights.jpeg)");

	if (img.empty())
	{
		std::cout << "Could not read the image: " << std::endl;
		return 1;
	}
	cv::namedWindow("First OpenCV Application", cv::WINDOW_AUTOSIZE);
	cv::imshow("First OpenCV Application", img);
	cv::moveWindow("First OpenCV Application", 0, 45);
	while (true)
	{
		int key = cv::waitKey(0);
		if (key == 'q')
		{
			cout << "Quitting the ImgDisplay after q is pressed" << endl;
			break;
		}
	}
	cv::destroyAllWindows();
	return 0;
}
