#ifndef EPHEMERIS_H
#define EPHEMERIS_H
#include "Rinex3NavData.hpp"
#include "Rinex3NavStream.hpp"
#include <iostream>
using namespace gpstk;
using namespace std;
class Ephemeris
{
private:
    //ECEF-координаты в метрах
    double x;
    double y;
    double z;
    bool is_file_open;
public:
    Ephemeris(string filename);
    double getX();
    double getY();
    double getZ();
    bool isFileOpen();
};

#endif // EPHEMERIS_H
