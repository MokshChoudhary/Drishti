#pragma once
#include "Core.h"

namespace Mini{
	using namespace cv;
	using namespace std;
	class Image
	{
	public:
		Image(string name);
		~Image();

		Mat modified;
		UMat umodified;

		string getWindowName();

		int closeOriginal();
		int closeModified();
		int ShowImageOrignal();
		int ShowImage(Mat image);

		void edgeDetecter();
		void helper(Mat &obj);
		void colorRemover(Mat& returnobj);
		void PixelSelected(Mat Object, int x, int y);
		void ShowImageModified();
		void setPixel(Point p);

		int testUnit(Mat Test);

	private:
		int thresh;
		int r, c, sizex, sizey;
		string WINDOW_NAME, filename;
		Mat original;
	};

	Image::Image(string name) {
		filename = name;
		original = imread(this->filename, IMREAD_COLOR);
		sizex = original.rows;
		sizey = original.cols;
		modified = imread(this->filename, IMREAD_COLOR);
		thresh = 70;
	}
	Image::~Image()
	{
	}

	string Image::getWindowName() {
		return WINDOW_NAME;
	}
	void Image::setPixel(Point p) {
		r = p.x;
		c = p.y;
	}
	
	int Image::ShowImageOrignal() {
		
		if (original.empty()) { return -1; }
		
		WINDOW_NAME = "Original";
		namedWindow("Original", WINDOW_FREERATIO);
		//resizeWindow("Original", 400, 300);	
		imshow("Original", original);
		return 0;
	}

	inline int Image::ShowImage(Mat image)
	{
		namedWindow("image", WINDOW_FREERATIO);
		imshow("image", image);
		return 0;
	}

	void Image::ShowImageModified() {
		WINDOW_NAME = "modifide";
		namedWindow("modifide", WINDOW_FREERATIO);
		//resizeWindow("modifiy", 1240, 700);
		imshow("modifide", modified);
		
	}

	void Mini::Image::edgeDetecter() {
		Mat HSV;
		GaussianBlur(original, HSV, Size(5, 5), 0);
		Canny(original,modified,100,200,3,true);

	}

	void Mini::Image::helper(Mat &obj) {
		Mat HSV;
		cvtColor(original,HSV,COLOR_BGR2GRAY);
		GaussianBlur(HSV, HSV, Size(5, 5), 0);
		Sobel(HSV, obj, CV_32F, 1, 0);
		double minVal, maxVal;
		minMaxLoc(obj, &minVal, &maxVal);
		obj.convertTo(obj, CV_8U, 255.0 / (maxVal - minVal), -minVal * 255.0 / (maxVal - minVal));
	}


	void Image::colorRemover(Mat &returnobj) {
		Mat HSV = original;

		Vec3b hsvPixel = HSV.at<Vec3b>(r, c);

		Scalar minBGR = cv::Scalar(hsvPixel.val[0] - thresh,
			hsvPixel.val[1] - thresh ,
			hsvPixel.val[2] - thresh );
		Scalar maxBGR = cv::Scalar(hsvPixel.val[0] + thresh,
			hsvPixel.val[1] + thresh,
			hsvPixel.val[2] + thresh);
		//cout << "Range : " <<maxBGR <<"," <<hsvPixel<<","<<minBGR << endl;
		Mat maskBGR, resultBGR;
		inRange(HSV, minBGR, maxBGR, maskBGR);
		bitwise_not(maskBGR, maskBGR);
		bitwise_and(HSV, HSV, resultBGR, maskBGR);
		
		returnobj = resultBGR;
	}

	int Image::closeOriginal() {
		 destroyWindow("Original");
		 return 0;
	}

	int Image::closeModified() {
		destroyWindow("Modified");
		return 0;
	}

	void Image::PixelSelected(Mat Object,int x,int y) {
		int Rt[2] = { x + 5 > sizex ? sizex : x + 5, y < 5 ? 0 : y - 5 };
		int Lt[2] = { x < 5 ? 0 : x - 5, y < 5 ? 0 : y - 5 };
		int Rb[2] = { x + 5 > sizex ? sizex : x + 5, y + 5 > sizey ? sizey : y + 5 };
		int Lb[2] = { x<5 ? 0 : x - 5, y + 5>sizey ? sizey : y + 5 };

		Rect block(Lt[0],Lt[1],10,10);

		rectangle(modified,block,Scalar(0,0,255),2,8,0);

		ShowImageModified();
	}

	
	int Image::testUnit(Mat frame) {
		Mat fgMask;
		frame = original;
		Ptr<BackgroundSubtractor> pBackSub;
		pBackSub = createBackgroundSubtractorKNN();
		pBackSub->apply(frame, fgMask);
		ShowImage(fgMask);
		return 0;
	}
}