#include "opencv2\opencv.hpp"

using namespace cv;

int main1(int argv,char** argc) {

	Mat image = imread("h.png", IMREAD_COLOR);

	Mat SplitImage[3];

	split(image, SplitImage);

	namedWindow("Orignal",WINDOW_FREERATIO);
	namedWindow("B", WINDOW_FREERATIO);
	namedWindow("G", WINDOW_FREERATIO);
	namedWindow("R", WINDOW_FREERATIO);

	imshow("Orignal", image);
	imshow("B", SplitImage[2]);
	imshow("G", SplitImage[1]);
	imshow("R", SplitImage[0]);

	waitKey();

	return 0;
}