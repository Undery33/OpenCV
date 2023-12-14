#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat src, src_gray, dst;

void Thresh(int value, void*) {
	threshold(src_gray, dst, value, 255, 0);
	imshow("결과 영상", dst);
}

int main() {
	Mat src = imread("C:/Users/htu12/OneDrive/바탕 화면/MICT융합과목/File/TEST2.jpg", IMREAD_COLOR);
	int value = 0;
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	namedWindow("결과 영상", WINDOW_AUTOSIZE);

	createTrackbar("임계값", "결과 영상", &value , 255, Thresh);

	while (true) {
		int c;
		c = waitKey(20);
		if ((char)c == 27) {
			break;
		}
	}
	return 0;
}