#include "Drishti.h"
using namespace std;
using namespace cv;

int main(int argn, char** argc) {
	cout << "Input : ";
	char a = getchar();
	if (a == '1') {
		while (1)
		{
			Mini::Video vid;
			cout << "Input : ";
			char s;
			cin >> s;
			if ((char)s == 'b') {
				if (!vid.BackGroundDetection("MOG2")) cout << "Working";
				else cout << "not working";
			}
			else if (s == 'e') {
				vid.edge_detection((std::string&)"video.mp4");
			}
			else if (s == 'l') {
				if (!vid.showVideo() == 0) cout << "Working ";
				else cout << "Not Working";
			}
			else if(s == 'q') {
				cout << "\nEnd statment";
				break;
			}
		}
	}
	else{
		while (1)
		{
			Mini::Image img("src//imges//2.jpg");
			Mini::Image* send = &img;
			MouseEvent st;
			if (!img.ShowImageOrignal() == 0) {
				cout << "this is a empty Image";
				break;
			}
			cout << "name window-> " << img.getWindowName() << endl;
			setMouseCallback("Original", st.MouseClick, &send);
			char s = (char)waitKey();
			if (s == (char)27) {
				destroyAllWindows();
				break;
			}
			else if (s == 'p') {
				if (st.Iflag == true) img.PixelSelected(img.modified, MouseEvent::xc, MouseEvent::yc);
				st.Iflag = false;
			}
			else if (s == 'c') {
				if (st.Iflag == true) {
					int64  e1 = getTickCount();

					img.setPixel(Point(MouseEvent::yc, MouseEvent::xc));
					img.colorRemover(img.modified);
					img.ShowImageModified();

					int64 e2 = getTickCount();

					cout << "Time :" << e2 - e1 << endl;

				}
			}
			else if (s == 'e') {
				int64  e1 = getTickCount();

				img.edgeDetecter();
				img.ShowImageModified();
				int64 e2 = getTickCount();

				cout << "Time :" << e2 - e1 << endl;
			}
			else if (s == 't') {
				int64  e1 = getTickCount();
				Mat o;
				img.testUnit(o);
				int64 e2 = getTickCount();

				cout << "Time :" << e2 - e1 << endl;
			}
			 
		}
	}
	return 0;
}