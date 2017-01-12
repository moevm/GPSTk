#include "../inc/Ephemeris.h"
#include "../inc/GeodeticSystemPoint.h"
#include "../inc/KMLFile.h"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    string RINEX_filename(argv[1]);
    string KML_filename(argv[2]);
    Ephemeris ephemeris(RINEX_filename);
    if(!ephemeris.isFileOpen())
        cout<<"Can not open RINEX-file\n";
    double x=ephemeris.getX();
    double y=ephemeris.getY();
    double z=ephemeris.getZ();
    GeodeticSystemPoint point;
    point.ConvertFromECEF(x, y, z);
    double latitude=point.getLatitude();
    double longitude=point.getLongitude();
    double elevation=point.getElevation();
    KMLFile KML_file(KML_filename);
    KML_file.CreateFile(latitude, longitude, elevation);
    exit(0);
    return 0;
}
