#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/Lenna.jpg");
	if (src.empty()) return -1;

	Mat dst1, dst2, dst3;
	float weights1[9] = { 0, -1, 0, -1, 5, -1 ,0, -1, 0 };
	float weights2[9] = { -1, -1, -1, -1, 9, -1 ,-1, -1, -1 };
	float weights3[9] = { 1, -2, 1, -2, 5, -2 ,1, -2, 1 };
	
	Mat mask1 = Mat(3, 3, CV_32F, weights1);
	Mat mask2 = Mat(3, 3, CV_32F, weights2);
	Mat mask3 = Mat(3, 3, CV_32F, weights3);

	filter2D(src, dst1, -1, mask1, Point(-1, -1), 0, BORDER_DEFAULT);
	filter2D(src, dst2, -1, mask2, Point(-1, -1), 0, BORDER_DEFAULT);
	filter2D(src, dst3, -1, mask3, Point(-1, -1), 0, BORDER_DEFAULT);

	imshow("src", src);
	imshow("sharpen 1", dst1);
	imshow("sharpen 2", dst2);
	imshow("sharpen 3", dst3);

	waitKey(0);
	return 0;
}