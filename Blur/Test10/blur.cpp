#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("C:/Users/htu12/OneDrive/���� ȭ��/MICT���հ���/File/Dog.jpg");
	Mat dst;

	blur(src, dst, Size(21, 21));
	imshow("source", src);
	imshow("result", dst);
	waitKey(0);
	return 0;
}