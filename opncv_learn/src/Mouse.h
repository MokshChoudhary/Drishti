#pragma once
#include "src/Core.h"

using namespace std;
using namespace cv;

class MouseEvent {
public:
	static bool Iflag;
	static int xc, yc;
	static Mat a;
	static void MouseClick(int event, int x, int y, int flag, void* ptr);
};

bool MouseEvent::Iflag = false;
int MouseEvent::xc = 0;
int MouseEvent::yc = 0;

void MouseEvent::MouseClick(int event, int x, int y, int flag, void* ptr) {
	Iflag = true;
	 if (event == EVENT_FLAG_LBUTTON) {
		 Iflag = true;
		 xc = x;
		 yc = y;
		cout << "MouseEventP x :" << x << ", y :" << y << endl;
	}
}
