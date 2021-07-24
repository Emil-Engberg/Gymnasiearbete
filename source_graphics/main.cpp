#include "compute.hpp"
#include "input.hpp"
#include "draw.hpp"
int main()
{
    vector<planet> objects = input("input.txt");
    calc(objects);
    return 0;
}
