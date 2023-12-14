#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/Lenna.jpg");
	Mat dst = Mat::zeros(Size(src.cols * 2, src.rows * 2), src.type());

	for (int y = 0; y < dst.rows; y++) {
		for (int x = 0; x < dst.cols; x++) {
			for (int c = 0; c < 3; c++) {
				const int newX = x / 2;
				const int newY = y / 2;
				dst.at<Vec3b>(y, x)[c] = src.at<Vec3b>(newY, newX)[c];
			}
		}
	}

	imshow("Image", src);
	imshow("Scaled", dst);
	waitKey(0);
	return 1;
}