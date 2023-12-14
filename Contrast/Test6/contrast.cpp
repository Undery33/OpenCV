#include "opencv2/opencv.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	double alpha = 1.0;
	int beta = 0;
	Mat image = imread("C:/Users/htu12/OneDrive/���� ȭ��/MICT���հ���/File/mict_opencv(1)/contrast.jpg");
	Mat oimage = Mat::zeros(image.size(), image.type());

	cout << "���� ���� �Է��ϼ��� : "; cin >> alpha;
	cout << "��Ÿ ���� �Է��ϼ��� : "; cin >> beta;

	image.convertTo(oimage, -1, alpha, beta);
	imshow("Original Image", image);
	imshow("New Image", oimage);
	waitKey();
	return 0;
}
