#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/Lenna.jpg");
	Mat dst = Mat();
	Size dsize = Size(src.cols, src.rows);

	Point Center = Point(0, 0);
	Mat M = getRotationMatrix2D(Center, -15, 1.0);

	warpAffine(src, dst, M, dsize, INTER_LINEAR);

	imshow("Image", src);
	imshow("Scaled", dst);
	waitKey(0);
	return 1;
}