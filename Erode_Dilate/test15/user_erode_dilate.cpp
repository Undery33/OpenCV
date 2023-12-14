#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

Mat user_erode(Mat img, Mat mask = Mat()) {

	Mat dst = Mat::zeros(img.size(), CV_8U);
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));

	int mcnt = (countNonZero(mask) > 0) ? 0 : 9;

	for (int i = 1; i < img.rows - 1; ++i) {
		for (int j = 1; j < img.cols - 1; ++j) {
			Rect roiRect(j - 1, i - 1, 3, 3);
			Mat roi = img(roiRect);
			Mat temp;
			bitwise_and(roi, element, temp);
			int cnt = countNonZero(temp);
			dst.at<uchar>(i, j) = (cnt == mcnt) ? 255 : 0;
		}
	}
	return dst;
}

Mat user_dilate(Mat img, Mat mask = Mat()) {

	Mat dst = Mat::zeros(img.size(), CV_8U);
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));

	int mcnt = countNonZero(mask);

	for (int i = 1; i < img.rows - 1; ++i) {
		for (int j = 1; j < img.cols - 1; ++j) {
			Rect roiRect(j - 1, i - 1, 3, 3);
			Mat roi = img(roiRect);
			Mat temp;
			bitwise_and(roi, element, temp);
			int cnt = countNonZero(temp);
			dst.at<uchar>(i, j) = (cnt > mcnt) ? 255 : 0;
		}
	}
	return dst;
}

int main() {
	Mat dst, erosion_dst, dilation_dst;
	Mat src = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/morph.jpg", IMREAD_GRAYSCALE);
	imshow("Original Image", src);

	threshold(src, dst, 127, 255, THRESH_BINARY);
	imshow("threshold Image", dst);

	erosion_dst = user_erode(dst);
	imshow("Erosion Demo", erosion_dst);

	dilation_dst = user_dilate(dst);
	imshow("Dilation Demo", dilation_dst);

	waitKey(0);
	return 0;
}