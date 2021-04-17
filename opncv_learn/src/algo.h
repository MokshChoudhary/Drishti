#pragma once
#include "src/Core.h"
namespace Mini {
	class algo {
	private:
		
	protected:

	public :
    /* TODO: Write correct RBG TO HSV converter function */
	/*std::vector<int>& RBGtoHSV(int R,int G,int B) {
			std::vector<int> a;
            double r, g, b;
            double re;
            std::fixed;
            std::setprecision(10);
            r = R / 255.0;
            g = G / 255.0;
            b = B / 255.0;

            // h, s, v = hue, saturation, value 
            double cmax = std::max(r, std::max(g, b)); // maximum of r, g, b 
            double cmin = std::min(r, std::min(g, b)); // minimum of r, g, b 
            double diff = cmax - cmin; // diff of cmax and cmin. 
            double h = -1;
            double s = -1;

            // if cmax and cmax are equal then h = 0 
            if (cmax == cmin)
                h = 0;

            // if cmax equal r then compute h 
            else if (cmax == r) {
                h = (60 * ((g - b) / diff) + 360);

                r = fmod(360,h);
                h = h + (r/10000000000);

            }
            // if cmax equal g then compute h 
            else if (cmax == g) {
                r = fmod(360, h);
                h = h + (r / 10000000000);

                h = fmod((60 * ((b - r) / diff) + 120), 360);
            }

            // if cmax equal b then compute h 
            else if (cmax == b) {
                r = fmod(360, h);
                h = h + (r / 10000000000);

                h = fmod((60 * ((r - g) / diff) + 240), 360);
            }

            // if cmax equal zero 
            if (cmax == 0)
                s = 0;
            else
                s = (diff / cmax) * 100;

            // compute v 
            double v = cmax * 100;

			
			a.push_back(h);//h 
			a.push_back(s);//s
			a.push_back(v);//v
			std::cout << a[0] <<" "<< a[1] <<" "<< a[2];
			return a;
		}*/
	};
}