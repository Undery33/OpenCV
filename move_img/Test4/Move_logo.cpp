#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat A = imread("C:/Users/htu12/OneDrive/���� ȭ��/MICT���հ���/File/image2.jpg");
	Mat B = imread("C:/Users/htu12/OneDrive/���� ȭ��/MICT���հ���/File/logo.png");
	Mat roi(A, Rect(A.cols - B.cols, A.rows - B.rows, B.cols, B.rows));
	Mat roi2(A, Rect(0, 0, B.cols, B.rows));
	Mat roi3(A, Rect(0, A.rows - B.rows, B.cols, B.rows));
	Mat roi4(A, Rect(A.cols - B.cols, 0, B.cols, B.rows));
	Mat roi5(A, Rect(A.cols/2, A.rows/2, B.cols, B.rows));
	B.copyTo(roi); // ���� �ϴ�
	B.copyTo(roi2); // ���� ���
	B.copyTo(roi3); // ���� �ϴ�
	B.copyTo(roi4); // ���� ���
	B.copyTo(roi5); // �߾�

	imshow("result", A);
	waitKey(0);
	return 0;
}