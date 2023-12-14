#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat A = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/Lenna.jpg");
	Mat B = A.clone();
	Mat C;
	A.copyTo(C);
	flip(B, B, 0);
	flip(C, C, 0);
	
	imshow("window 1", A);
	imshow("window 2", B);
	imshow("window 3", C);

	waitKey(0);
	return 0;
}