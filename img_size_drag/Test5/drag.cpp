// �̴� ���伥 ����� p104, p105
// 201995102 ȫ����
#include <opencv2/opencv.hpp>

using namespace cv;

// cropping : ���콺�� Ŭ���ϰ� ������ ���� ������ ǥ���� �� �ֵ��� �ϴ� ����
// check_rec : ���� �׸� ������ Ȯ���ϴ� ����
bool cropping = false, check_rec = false;
int mx1, my1, mx2, my2;
// clone�� ���������� ����
Mat img, roi, clone;

void onMouse(int event, int x, int y, int flags, void* param) {
    if (event == EVENT_LBUTTONDOWN) {
        // ���� ���� �׸� ������ ������ ���, ���ο� �̹����� ��ü
        if (check_rec) img = clone.clone();
        mx1 = x;
        my1 = y;
        // ���콺�� ������ ������ ������ �׷��� �� �ֵ��� ���
        cropping = true;
    }
    else if (event == EVENT_MOUSEMOVE && cropping) {    // ���콺 ������ ���� �̺�Ʈ
        // ���콺�� �����̸� x, y�� ���� �׻� �޶����� ������ �̹��� ����
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
        // ���콺�� ������ ������ ������ �׷����� �ʵ��� false�� ����
        cropping = false;
        // ������ �׷������Ƿ�(�����ϹǷ�) true�� ����
        check_rec = true;
        rectangle(img, Rect(mx1, my1, mx2 - mx1, my2 - my1), Scalar(0, 255, 0), 2);
        imshow("image", img);
    }
}

int main() {
    img = imread("C:/Users/htu12/OneDrive/���� ȭ��/MICT���հ���/File/Lenna.jpg");
    imshow("image", img);
    clone = img.clone();

    setMouseCallback("image", onMouse);

    while (1) {
        int key = waitKey(100);
        if (key == 'q') break;
        else if (key == 'c') {
            roi = clone(Rect(mx1, my1, mx2 - mx1, my2 - my1));
            imwrite("C:/Users/htu12/OneDrive/���� ȭ��/MICT���հ���/File/result.jpg", roi);
        }
    }
    return 0;
}
