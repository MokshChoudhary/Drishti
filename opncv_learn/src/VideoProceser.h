#pragma once
#include "Core.h"
namespace Mini {
	class Video
	{
	public:
		Video();
		int showVideo(const string &videoname);
		int BackGroundDetection(string algo);
		void edge_detection(string& path);
		int showVideo();

		~Video();

	private:

	};

	Video::Video()
	{
	}

	int Video::showVideo(const string& videoname) {
		VideoCapture capture((string)videoname, 0);
		
		if (!capture.isOpened()) return -1;
		Mat outputFile;
		while (true)
		{
			capture >> outputFile;

		}

	}

	void Video::edge_detection(std::string& path) {
		VideoCapture capture(path);
		if (!capture.isOpened()) return;
		Mat frame,Mframe; 
		float kdata[] = { 1, 0, -1, 1, 0, -1, 1, 0, -1 };
		Mat keranl(3,3,CV_8UC1,kdata);
		while (1) {
			capture >> frame;
			filter2D(frame, Mframe, -1, keranl, Point(-1, -1), 0,BORDER_DEFAULT);
			
			namedWindow("video", WINDOW_FREERATIO);
			imshow("video", Mframe);
		}
	}


	int Video::showVideo() {
		VideoCapture cap(0);

		if (!cap.isOpened()) {
			cout << "Can't open this file";
			return -1;
		}

		while (1) {
			Mat frame;
			cap >> frame;

			imshow("Video", frame);

			int keyboard = waitKey(60);
			if (keyboard == 'q' || keyboard == 27)
				break;
		}

		destroyAllWindows();

		return 0;
	}

	int Video::BackGroundDetection(string algo) {
		Ptr<BackgroundSubtractor> pBackSub;
		if (algo == "MOG2")
			pBackSub = createBackgroundSubtractorMOG2();
		else
			pBackSub = createBackgroundSubtractorKNN();
		VideoCapture capture(0);
		if (!capture.isOpened()) {
			//error in opening the video input
			cerr << "Unable to open: WebCam " << endl;
			return 0;
		}
		Mat frame, fgMask;
		while (true) {
			capture >> frame;
			if (frame.empty())
				break;
			//update the background model
			pBackSub->apply(frame, fgMask);
			//get the frame number and write it on the current frame
			rectangle(frame, cv::Point(10, 2), cv::Point(100, 20),
				cv::Scalar(255, 255, 255), -1);
			stringstream ss;
			ss << capture.get(CAP_PROP_POS_FRAMES);
			string frameNumberString = ss.str();
			putText(frame, frameNumberString.c_str(), cv::Point(15, 15),
				FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 0, 0));
			//show the current frame and the fg masks
			//imshow("Frame", frame);
			imshow("FG Mask", fgMask);
			//get the input from the keyboard
			int keyboard = waitKey(30);
			if (keyboard == 'q' || keyboard == 27)
				break;
		}
		destroyAllWindows();
		return 0;
	}

	Video::~Video()
	{
	}
}