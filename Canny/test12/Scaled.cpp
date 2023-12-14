#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/Lenna.jpg");
	Mat dst = Mat::zeros(Size(src.cols, src.rows), src.type());

	for (int y = 0; y < src.rows; y++) {
		for (int x = 0; x < src.cols; x++) {
			for (int c = 0; c < 3; c++) {
				const int newX = x + 20;
				const int newY = y + 60;
				if(newX > 0 && newY > 0 && newX < src.cols && newY < src.rows)
					dst.at<Vec3b>(newY, newX)[c] = src.at<Vec3b>(y, x)[c];
			}
		}
	}

	imshow("Image", src);
	imshow("Scaled", dst);
	waitKey(0);
	return 1;
}