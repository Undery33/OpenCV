#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/Lenna.jpg", IMREAD_GRAYSCALE), grad1, grad2, grad3;
	int scale = 1, delta = 0;
	if (src.empty()) return -1;

	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;

	GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);

	Sobel(src, grad_x, CV_16S, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	Sobel(src, grad_y, CV_16S, 0, 1, 3, scale, delta, BORDER_DEFAULT);

	convertScaleAbs(grad_x, abs_grad_x);
	convertScaleAbs(grad_y, abs_grad_y);

	addWeighted(abs_grad_x, 0.5, 0, 0.5, 0, grad1);
	addWeighted(0, 0.5, abs_grad_y, 0.5, 0, grad2);
	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad3);

	imshow("Image", src);
	imshow("Sobel 1", grad1);
	imshow("Sobel 2", grad2);
	imshow("Sobel 3", grad3);
	waitKey(0);
	return 0;
}

/*
#include "opencv2/opencv.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
	Mat src = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/Lenna.jpg", IMREAD_GRAYSCALE);
	Mat src_gray, dst;
	int kernel_size = 3, scale = 1, delta = 0, ddepth = CV_16S;
	if (src.empty()) return -1;

	// GaussianBlur(src, src, Size(3, 3), 0, 0, BORDER_DEFAULT);
	Mat abs_dst;
	Laplacian(src, dst, ddepth, kernel_size, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(dst, abs_dst);

	imshow("Image", src);
	imshow("Laplacian", abs_dst);
	waitKey(0);
	return 0;
}
*/