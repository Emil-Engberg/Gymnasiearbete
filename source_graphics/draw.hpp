#ifndef draw_hpp
#define draw_hpp
#include <SFML/Graphics.hpp>
#include "compute.hpp"
valarray<double> transform3d(valarray<double> cords, double scale, double rotx, double roty, double rotz);
void draw(vector<planet>);
#endif
    
