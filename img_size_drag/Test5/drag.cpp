// 미니 포토샵 만들기 p104, p105
// 201995102 홍태의
#include <opencv2/opencv.hpp>

using namespace cv;

// cropping : 마우스를 클릭하고 움직일 때만 도형을 표시할 수 있도록 하는 변수
// check_rec : 이전 그린 도형을 확인하는 변수
bool cropping = false, check_rec = false;
int mx1, my1, mx2, my2;
// clone을 전역변수로 지정
Mat img, roi, clone;

void onMouse(int event, int x, int y, int flags, void* param) {
    if (event == EVENT_LBUTTONDOWN) {
        // 만약 이전 그린 도형이 존재할 경우, 새로운 이미지로 교체
        if (check_rec) img = clone.clone();
        mx1 = x;
        my1 = y;
        // 마우스를 움직일 때마다 도형이 그려질 수 있도록 허용
        cropping = true;
    }
    else if (event == EVENT_MOUSEMOVE && cropping) {    // 마우스 움직일 때의 이벤트
        // 마우스를 움직이면 x, y의 값이 항상 달라지니 임의의 이미지 생성
        Mat temp_img = img.clone();
        rectangle(temp_img, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(0, 255, 0), 2);
        mx2 = x;
        my2 = y;
        rectangle(temp_img, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(0, 255, 0), 2);
        imshow("image", temp_img);
    }
    else if (event == EVENT_LBUTTONUP) {
        mx2 = x;
        my2 = y;
        // 마우스를 움직일 때마다 도형이 그려지지 않도록 false로 조정
        cropping = false;
        // 도형이 그려졌으므로(존재하므로) true로 조정
        check_rec = true;
        rectangle(img, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(0, 255, 0), 2);
        imshow("image", img);
    }
}

int main() {
    img = imread("C:/Users/htu12/OneDrive/바탕 화면/MICT융합과목/File/Lenna.jpg");
    imshow("image", img);
    clone = img.clone();

    setMouseCallback("image", onMouse);

    while (1) {
        int key = waitKey(100);
        if (key == 'q') break;
        else if (key == 'c') {
            roi = clone(Rect(mx1, my1, mx2 - mx1, my2 - my1));
            imwrite("C:/Users/htu12/OneDrive/바탕 화면/MICT융합과목/File/result.jpg", roi);
        }
    }
    return 0;
}
