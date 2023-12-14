#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat A = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/Lenna.jpg");
	Mat M = Mat::eye(5, 10, CV_64F);
	Mat Row = M.row(1);
	Mat Col = M.col(M.rows);
	Mat E = M(Range::all(), Range(1, 3));
	cout << "Row = " << endl << Row << endl << endl;
	cout << "Col = " << endl << Col << endl << endl;
	cout << "Range = " << endl << E << endl << endl;
	imshow("window 1", A);
	waitKey(0);
	return 0;
}