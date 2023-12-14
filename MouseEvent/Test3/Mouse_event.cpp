#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main() {
	Mat img = imread("C:/Users/htu12/OneDrive/바탕 화면/MICT융합과목/File/mict_opencv(1)/dog.jpg", IMREAD_COLOR);
	if (img.empty()) { cout << "영상을 읽을 수 없음" << endl; }
	imshow("img", img);
	int x = 300;
	int y = 300;
	while (1) {
		int key = waitKey(100);
		if (key == 'q') break;
		else if (key == 'a') x -= 10;
		else if (key == 'w') y -= 10;
		else if (key == 'd') x += 10;
		else if (key == 's') y += 10;
		circle(img, Point(x, y), 200, Scalar(0, 255, 0), 5);
		imshow("img", img);
	}
	return 0;
}

// 마우스 이벤트

void onMouse(int event, int x, int y, int flags, void* param) {
	if (event == EVENT_LBUTTONDOWN) {
		Mat& img = *(Mat*)(param);
		circle(img, Point(x, y), 120, Scalar(0, 255, 0), 10);	// 200 -> 120
		putText(img, "I found a dog!", Point(x - 250, y), FONT_HERSHEY_COMPLEX, 0.5, 255, 2);
		// (x, y + 100) -> (x - 250, y) / Font change / scale : 2.0 -> 0.5
		imshow("src", img);
	}
	else if (event == EVENT_RBUTTONDOWN) {}
	else if (event == EVENT_MBUTTONDOWN) {}
	else if (event == EVENT_MOUSEMOVE) {
	}
}
int main() {
	Mat src = imread("C:/Users/htu12/OneDrive/바탕 화면/MICT융합과목/File/mict_opencv(1)/dog.jpg", IMREAD_COLOR);
	if (src.empty()) { cout << "영상을 읽을 수 없음" << endl; }
	imshow("src", src);

	setMouseCallback("src", onMouse, &src);
	waitKey(0);
	return 0;
}