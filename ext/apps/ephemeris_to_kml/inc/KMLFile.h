#ifndef KMLFILE_H
#define KMLFILE_H
#include <iostream>
using namespace std;
class KMLFile
{
private:
    string filename;
public:
    KMLFile(string filename);
    void CreateFile(double latitude, double longitude, double elevation);
};

#endif // KMLFILE_H
