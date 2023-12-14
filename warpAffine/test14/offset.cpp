#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/Lenna.jpg", IMREAD_GRAYSCALE);
	int rows = src.rows;
	int cols = src.cols;
	Mat dst = src.clone();

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
				int offset_x = (int)(25.0 * sin(2 * 3.14 * j / 180));
				int offset_y = (int)(25.0 * sin(2 * 3.14 * j / 97));
				if (i + offset_y < rows)
					dst.at<uchar>(i, j) = src.at<uchar>((i + offset_y) % rows, j);
				else {
					dst.at<uchar>(i, j) = 0;
				}
			}
	}

	imshow("src", src);
	imshow("dst", dst);
	waitKey(0);
	return 0;
}