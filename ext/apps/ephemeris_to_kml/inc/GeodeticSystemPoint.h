#ifndef GEODETICSYSTEMPOINT_H
#define GEODETICSYSTEMPOINT_H
#include "math.h"
class GeodeticSystemPoint
{
private:
    double latitude;
    double longitude;
    double elevation;//высота над уровнем моря в метрах
public:
    GeodeticSystemPoint();
    GeodeticSystemPoint(double latitude, double longitude, double elevation);
    void ConvertFromECEF(double x, double y, double z);
    double getLatitude();
    double getLongitude();
    double getElevation();
};

#endif // GEODETICSYSTEMPOINT_H
