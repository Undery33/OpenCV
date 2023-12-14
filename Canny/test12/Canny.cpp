#include "opencv2/opencv.hpp"

using namespace std;
using namespace cv;

Mat src, src_gray;
Mat dst, detected_edges;
int edgeThresh = 1;
int lowThreshold = 28;
int const max_lowThreshold = 100;
int ratios = 3;
int kernel_size = 3;

static void CannyThreshold(int, void*) {
	blur(src, detected_edges, Size(3, 3));
	Canny(detected_edges, detected_edges, lowThreshold, lowThreshold * ratios, kernel_size);

	dst = Scalar::all(0);
	src.copyTo(dst, detected_edges);
	imshow("image", src);
	imshow("Canny", dst);
}

int main() {
	src = imread("C:/Users/htu12/OneDrive/¹ÙÅÁ È­¸é/MICTÀ¶ÇÕ°ú¸ñ/File/Lenna.jpg", IMREAD_GRAYSCALE);
	if (src.empty()) { return -1; }
		
	CannyThreshold(0, 0);

	waitKey(0);
	return 0;
}