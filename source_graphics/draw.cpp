#include "draw.hpp"
#include "compute.hpp"
valarray<double> transform3d(valarray<double> cords, double scale, double rotx, double roty, double rotz){
	rotx*=M_PI/180;
	roty*=M_PI/180;
	rotz*=M_PI/180;
	double x = (cords[0]/scale);
	double y = (cords[1]/scale);
	double z = (cords[2]/scale);
	double xt, yt;
	xt = x*cos(rotx)*cos(roty)+y*(cos(rotx)*sin(roty)*sin(rotz)-sin(rotx)*cos(rotz))+z*(cos(rotx)*sin(roty)*cos(rotz)+sin(rotx)*sin(rotz));
	yt = x*sin(rotx)*cos(roty)+y*(sin(rotx)*sin(roty)*sin(rotz)+cos(rotx)*cos(rotz))+z*(sin(rotx)*sin(roty)*cos(rotz)-cos(rotx)*sin(rotz));
	valarray<double> output={xt,yt};
	return(output);
}
