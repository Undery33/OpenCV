#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
	Mat LoadedImage = imread("C:/Users/htu12/OneDrive/���� ȭ��/MICT���հ���/File/Lenna.jpg", IMREAD_COLOR);
	Mat NewImage;
	imshow("Original Image", LoadedImage);

	cout << endl << endl << "�� ������ ũ�� : " << LoadedImage.size() << endl;
	resize(LoadedImage, NewImage, Size(300, 200));
	imshow("New Image", NewImage);
	waitKey(0);
	return 0;
}