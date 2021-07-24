#include "input.hpp"
vector<planet> input(string filename) {
    vector<planet> objects;
    string line;
    ifstream myfile (filename);
    while ( getline (myfile,line) ) {
        if(line == "") {
            double data[8];
            for(int i = 0; i<8; i++) {
                getline (myfile,line);
                data[i] = stod(line);
            }
            objects.push_back(planet({data[0], data[1], data[2]}, {data[3], data[4], data[5]}, data[6], data[7]));
        }
    }
    return objects;
}
