#ifndef compute_hpp
#define compute_hpp
#include <iostream>
#include <fstream>
#include <valarray>
#include <math.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
using namespace std;
class planet {
    public:
        valarray<double> pos = {};
        valarray<double> vel = {};
        valarray<double> acc = {0, 0, 0};
        valarray<double> force = {0, 0, 0};
        double radius = 0;
        double mass = 0;
        planet(valarray<double> apos, valarray<double> avel, double aradius, double amass) {
            pos = apos;
            vel = avel;
            radius = aradius;
            mass = amass;
        }
        void calc_pos(double step) {
            acc = (force / mass);
            vel += acc * step;
            pos += vel * step;
            force = {0, 0, 0};
        }
};
void calc(vector<planet> objects, int obv, int target, int focus, time_t end_date);
#endif
    
