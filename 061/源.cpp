#include <iostream>
#include <opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	VideoCapture cap(0);

	while (1)
	{
		cv::Mat frame;
		cv::Mat CannyMat1;
		cv::Mat CannyMat2;
		cv::Mat Edge_X;
		cv::Mat Edge_Y;
		cap >> frame;


		Canny(frame, CannyMat1, 50, 150);

		//x,y·½ÏòÎ¢·Ö
		Sobel(frame, Edge_X, CV_16SC1, 1, 0, 3);
		Sobel(frame, Edge_Y, CV_16SC1, 0, 1, 3);
		Canny(Edge_X, Edge_Y, CannyMat2, 50, 150);

		imshow("frame", frame);
		imshow("CannyMat1", CannyMat1);
		imshow("CannyMat2", CannyMat2);
		waitKey(30);

	}
	//std::cout << "Hello World!\n";
}