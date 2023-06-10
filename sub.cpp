#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

Mat img_color;

void mouse_callback(int event, int x, int y, int flags, void* param);

int main()
{
	namedWindow("img_color");
	setMouseCallback("img_color", mouse_callback);

	VideoCapture cap(1);																																												// ī�޶� ���� �κ� : ���� 0��° ī�޶�

	if (!cap.isOpened()) {
		cout << "ī�޶� �� �� �����ϴ�." << endl;
		return -1;
	}

	while (1) {
		cap.read(img_color);
		imshow("img_color", img_color);

		if (waitKey(1) > 0)
			break;
	}
	return 0;
}

void mouse_callback(int event, int x, int y, int flags, void* param)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		cout << "�ش� ��ġ�� ��ǥ" << x << endl;
		cout << " x = " << x << endl;
		cout << " y = " << y << endl;
	}
}