#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

Mat user_erode(Mat img, Mat mask = Mat()) {

	Mat dst = Mat::zeros(img.size(), CV_8U);
	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));

	int mcnt = (countNonZero(mask) > 0) ? 9 : 0;

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
			dst.at<uchar>(i, j) = (cnt == 0) ? 0 : 255;
		}
	}
	return dst;
}

int main() {
	Mat dst, open, close;
	Mat src = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/letterj.png", IMREAD_GRAYSCALE);

	threshold(src, src, 127, 255, THRESH_BINARY);

	Mat saltpepper_noise = Mat::zeros(src.rows, src.cols, CV_8U);
	randu(saltpepper_noise, 0, 255);

	Mat black = saltpepper_noise < 30;
	Mat white = saltpepper_noise > 225;

	Mat saltpepper_img = src.clone();
	saltpepper_img.setTo(255, white);
	saltpepper_img.setTo(0, black);

	imshow("src", saltpepper_img);

	Mat element = getStructuringElement(MORPH_CROSS, Size(3, 3));

	open = user_erode(user_dilate(saltpepper_img, element), element);
	imshow("Opening Demo", open);

	close = user_dilate(user_erode(saltpepper_img, element), element);
	imshow("Closing Demo", close);
	waitKey(0);
	return 0;
}