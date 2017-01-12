#include "../inc/Ephemeris.h"
Ephemeris::Ephemeris(string filename)
{
    Rinex3NavStream ephemeris_file(filename.data());
    if(!ephemeris_file.is_open())
    {
        is_file_open=false;
        return;
    }
    else
        is_file_open=true;
    Rinex3NavData ephemeris_data;
    ephemeris_file>>ephemeris_data;
    GloEphemeris ephemeris=ephemeris_data.operator GloEphemeris();
    Xvt xvt=ephemeris.svXvt(ephemeris.getEpochTime());
    Vector<double> pos=xvt.getPos().toVector();
    x=pos[0];
    y=pos[1];
    z=pos[2];
}
double Ephemeris::getX()
{
    return x;
}
double Ephemeris::getY()
{
    return y;
}
double Ephemeris::getZ()
{
    return z;
}
bool Ephemeris::isFileOpen()
{
    return is_file_open;
}
