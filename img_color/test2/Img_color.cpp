#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat image = Mat(400, 600, CV_8UC3, Scalar(0, 0, 0));

	line(image, Point(100, 100), Point(300, 300), Scalar(0, 0, 255), 7);
	rectangle(image, Point(250, 30), Point(450, 200), Scalar(0, 255, 0), 5);
	circle(image, Point(400, 300), 60, Scalar(255, 0, 0), 3);
	ellipse(image, Point(100, 250), Point(100, 60), 135, 0, 360, Scalar(255, 255, 255), 5);

	imshow("Image", image);

	// 이미지 흑백, 상하좌우반전

	Mat image = imread("C:/Users/htu12/OneDrive/바탕 화면/MICT융합과목/File/Lenna.jpg", IMREAD_COLOR);
	if (image.empty()) { cout << "영상을 읽을 수 없음" << endl; }
	imshow("image", image);

	Mat gray;
	cvtColor(image, gray, COLOR_BGR2GRAY);

	imshow("gray", gray);
	Mat dst1;
	flip(image, dst1, 1);
	imwrite("C:/Users/htu12/OneDrive/바탕 화면/MICT융합과목/File/Lenna_dst1.jpg", dst1);
	Mat dst2;
	flip(image, dst2, 0);
	imwrite("C:/Users/htu12/OneDrive/바탕 화면/MICT융합과목/File/Lenna_dst2.jpg", dst2);
	Mat dst3;
	flip(image, dst3, -1);
	imwrite("C:/Users/htu12/OneDrive/바탕 화면/MICT융합과목/File/Lenna_dst3.jpg", dst3);

	waitKey(0);
	return 0;
}