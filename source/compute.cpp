#include "compute.hpp"
double abs2(valarray<double> arr1) {
    double sum = 0;
    for (unsigned int i = 0; i < size(arr1); i++) {
        sum += pow(arr1[i], 2);
    }
    return(sqrt(sum));
}
valarray<double> gravity(valarray<double> pos1,
    valarray<double> pos2, double mass1, double mass2) {
    const double G = 6.6743015e-11;
    valarray<double> d = { pos1 - pos2 };
    double d_abs = abs2(d);
    return(-G * (mass1 * mass2) / pow(d_abs, 2) * (d) / d_abs);

}
bool transit(double radius1, valarray<double> pos1, valarray<double> pos2,
    double radius2, valarray<double> pos3, double radius3) {
    
    double d1 = abs2(pos1-pos2);
    double d3 = abs2(pos1-pos3);
    if(d3 < d1) {
        double d2 = abs2(pos2-pos3);
        double x = (radius1*d1)/(radius2-radius1);
        double v1 = acos((pow(d3,2)+pow(d1,2)-pow(d2,2))/(2*d3*d1));
        double v2 = M_PI-v1;
        double d4 = sqrt(pow(x,2)+pow(d3,2)-2*x*d3*cos(v2));
        double v3 = asin((sin(v2)*d3)/d4)-asin(radius3/d4);
        if(asin(radius2/(d1+x)) > v3 && d4> x ) {
            return true;
        }
    }
    return false;
}
void calc_gravity(planet& obj1, planet& obj2) {
    valarray<double> force = gravity(obj1.pos, obj2.pos, obj1.mass, obj2.mass);
    obj1.force += force;
    obj2.force += -force;
}
void calc(vector<planet> objects, int obv, int target, int focus, time_t end_date)
{
    ofstream MyFile("output.txt");
    string step_string;
    cout << "Step (s): ";
    cin >> step_string;
    double step = stod(step_string);
    int b;
    bool new_transit = false;
    bool old_transit = false;
    for (double t = 1577836800; abs(t - end_date) > abs(step); t += step ) {
        b = 1;
        new_transit = transit(objects[obv].radius, objects[obv].pos, objects[focus].pos,
            objects[focus].radius, objects[target].pos, objects[target].radius);
        if (new_transit != old_transit) {
            time_t transit_time = (long long)t;
            string date = asctime(gmtime(&transit_time));
            if (old_transit == false) {
                date[size(date)-1] = '|';
            }
            MyFile << date << flush;
            cout << date;
        }
        old_transit = new_transit;
        for (unsigned int x = 1; x < size(objects); x++) {
            for (int y = 0; y < b; y++) {
                calc_gravity(objects[x], objects[y]);
            }
            b++;
        }
        for (unsigned int i = 0; i < size(objects); i++) {
            objects[i].calc_pos(step);
        }
    }
    MyFile.close();
}

