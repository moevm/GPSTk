#include "../inc/KMLFile.h"
#include <fstream>
#include <string>
#include <boost/lexical_cast.hpp>
KMLFile::KMLFile(string filename)
{
    this->filename=filename;
}
void KMLFile::CreateFile(double latitude, double longitude, double elevation)
{
    ofstream file;
    file.open(filename.data());
    file<<"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
    file<<"<kml xmlns=\"http://www.opengis.net/kml/2.2\"> <Placemark>\n";
    file<<"<name>Спутник</name>\n";
    file<<"<Style id=\"sn_ylw-pushpin\">\n";
    file<<"<IconStyle>\n";
    file<<"<scale>25</scale>\n";
    file<<"</IconStyle>\n";
    file<<"<LabelStyle>\n";
    file<<"<scale>25</scale>\n";
    file<<"</LabelStyle>\n";
    file<<"</Style>\n";
    file<<"<Point>\n";
    file<<"<altitudeMode>relativeToGround</altitudeMode>\n";
    string coordinates="<coordinates>";
    coordinates+=boost::lexical_cast<string>(longitude);
    coordinates+=",";
    coordinates+=boost::lexical_cast<string>(latitude);
    coordinates+=",";
    coordinates+=boost::lexical_cast<string>(elevation);
    coordinates+="</coordinates>\n";
    file<<coordinates.data();
    file<<"</Point>\n";
    file<<"</Placemark> </kml>";
    file.close();
}
