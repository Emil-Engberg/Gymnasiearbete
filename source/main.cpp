#include "compute.hpp"
#include "input.hpp"
int main()
{
    struct tm date;
    int year, month, day, hour, minutes, seconds;
    time_t end_date;
    vector<planet> objects = input("input.txt");
    int obv, target, focus;
    string in;
    cout <<     "0 = earth \n1 = sun \n2 = moon \n3 = mercury \n4 = venus \n5 = Mars \n6 = Jupiter \n7 = Saturn \n8 = Uranus \n9 = Neptune\n";
    cout << "Observer: ";
    cin >> in;
    obv = stoi(in);
    cout << "Target: ";
    cin >> in;
    target = stoi(in);
    cout << "Focus: ";
    cin >> in;
    focus = stoi(in);
    cout << "Year:";
    cin >> in;
    year = stoi(in) - 1900;
    cout << "Month:";
    cin >> in;
    month = stoi(in)-1;
    cout << "Day:";
    cin >> in;
    day = stoi(in);
    cout << "Hour:";
    cin >> in;
    hour = stoi(in) ;
    cout << "Minutes:";
    cin >> in;
    minutes = stoi(in);
    cout << "Seconds:";
    cin >> in;
    seconds = stoi(in);
    
    date = {.tm_sec = seconds, .tm_min = minutes, .tm_hour = hour, .tm_mday = day, .tm_mon=month, .tm_year = year};
    end_date = mktime(&date) - timezone;
    calc(objects, obv, target, focus, end_date);
    return 0;
}
