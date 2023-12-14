#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/Lenna.jpg", IMREAD_GRAYSCALE);
	Mat dst = Mat::zeros(Size(src.cols * 2, src.rows * 2), src.type());
	
	for (int y = 0; y < dst.rows; y++) {
		for (int x = 0; x < dst.cols; x++) {
			const int newX = x / 2.0;
			const int newY = y / 2.0;
			dst.at<uchar>(y, x) = src.at<uchar>(newY, newX);
		}
	}
	imshow("Image", src);
	imshow("Scaled", dst);
	waitKey(0);
	return 1;
}