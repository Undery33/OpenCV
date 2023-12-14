#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/Lenna.jpg");

	Mat dst(src.size(), CV_8UC3, Scalar(0));
	if (src.empty()) { return -1; }

	for (int y = 1; y < src.rows - 1; y++) {
		for (int x = 1; x < src.cols - 1; x++) {
			for (int c = 0; c < 3; c++) {
				int sum = 0;
				sum += src.at<Vec3b>(y - 1, x - 1)[c];
				sum += src.at<Vec3b>(y, x - 1)[c];
				sum += src.at<Vec3b>(y + 1, x - 1)[c];
				sum += src.at<Vec3b>(y - 1, x)[c];
				sum += src.at<Vec3b>(y, x)[c];
				sum += src.at<Vec3b>(y + 1, x)[c];
				sum += src.at<Vec3b>(y - 1, x + 1)[c];
				sum += src.at<Vec3b>(y, x + 1)[c];
				sum += src.at<Vec3b>(y + 1, x + 1)[c];
				dst.at<Vec3b>(y, x)[c] = sum / 9;
			}
		}
	}

	imshow("initial", src);
	imshow("final", dst);
	waitKey(0);
	return 0;
}