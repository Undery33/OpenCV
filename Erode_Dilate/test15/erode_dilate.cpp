#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat dst, erosion_dst, dilation_dst;
	Mat src = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/morph.jpg");

	threshold(src, dst, 127, 255, THRESH_BINARY);
	imshow("dst", dst);

	Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
	erode(dst, erosion_dst, element);
	imshow("Erosion Demo", erosion_dst);
	dilate(dst, dilation_dst, element);
	imshow("Dilation Demo", dilation_dst);
	waitKey(0);
	return 0;
}