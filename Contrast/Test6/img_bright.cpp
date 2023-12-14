#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat img = imread("C:/Users/htu12/OneDrive/���� ȭ��/MICT���հ���/File/Lenna.jpg", IMREAD_GRAYSCALE);
	imshow("Original Image", img);

	if(img.isContinuous()) {
		uchar* p = img.data;
		for (int c = 0; c < img.cols * img.rows; c++) {
			*p++ = saturate_cast<uchar>(*p + 30);
		}
	}

	imshow("New Image", img);
	waitKey(0);
	return 0;
}
