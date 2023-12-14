#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

void thresh(Mat& img, int value) {
	for (int r = 0; r < img.rows; r++) {
		for (int c = 0; c < img.cols; ++c) {
			if (img.at<uchar>(r, c) > value) {
				img.at<uchar>(r, c) = 255;
			}
			else {
				img.at<uchar>(r, c) = 0;
			}
		}
	}
}

int main() {
	Mat image = imread("C:/Users/htu12/OneDrive/���� ȭ��/MICT���հ���/File/Lenna.jpg", IMREAD_GRAYSCALE);
	int threshold_value;
	imshow("imgae", image);
	cout << "�� �Է� : "; cin >> threshold_value;
	thresh(image, threshold_value);
	imshow("New image", image);
	waitKey();
	return 0;
}