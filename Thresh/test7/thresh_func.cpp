#include "opencv2/opencv.hpp"
#include <stdlib.h>
#include <stdio.h>

using namespace std;
using namespace cv;

Mat src, src_gray, dst;

void Thresh(int value, void*) {
	threshold(src_gray, dst, value, 255, 0);
	imshow("��� ����", dst);
}

int main() {
	Mat src = imread("C:/Users/htu12/OneDrive/���� ȭ��/MICT���հ���/File/TEST2.jpg", IMREAD_COLOR);
	int value = 0;
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	namedWindow("��� ����", WINDOW_AUTOSIZE);

	createTrackbar("�Ӱ谪", "��� ����", &value , 255, Thresh);

	while (true) {
		int c;
		c = waitKey(20);
		if ((char)c == 27) {
			break;
		}
	}
	return 0;
}