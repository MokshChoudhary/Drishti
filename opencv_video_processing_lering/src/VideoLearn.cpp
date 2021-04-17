#include "VideoLearn.h"

using namespace std;
using namespace cv;

VideoLearn::VideoLearn() {

}

VideoLearn::~VideoLearn() {

}

int VideoLearn::CreateApplication() {
	VideoCapture  cap("video.mp4");
	
	if (!cap.isOpened()) {
		cout << "Can't open this file";
		return -1;
	}

	while (1) {
		Mat frame;
		cap >> frame;

		if (frame.empty()) {
			break;
		}

		imshow("Video", frame);

		char esc = (char)waitKey();
		if (esc == waitKey()) {
			break;
		}
	}
	cap.release();

	destroyAllWindows();
	return 0;
}