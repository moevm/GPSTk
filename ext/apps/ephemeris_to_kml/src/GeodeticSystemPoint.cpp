#include "../inc/GeodeticSystemPoint.h"

GeodeticSystemPoint::GeodeticSystemPoint()
{
}
GeodeticSystemPoint::GeodeticSystemPoint(double latitude, double longitude, double elevation)
{
    this->latitude=latitude;
    this->longitude=longitude;
    this->elevation=elevation;
}
void GeodeticSystemPoint::ConvertFromECEF(double x, double y, double z)
{
    const double a=6378137;//экваториальный радиус земли в метрах
    const double b=6356752.3142;//полярный радиус земли в метрах
    const double e=sqrt(1-b*b/(a*a));
    const double e1=(b/a)*e;
    double r=sqrt(x*x+y*y);
    double F=54*b*b*z*z;
    double E=sqrt(a*a-b*b);
    double G=r*r+(1-e*e)*z*z-e*e*E*E;
    double c=(pow(e, 4)*F*r*r)/pow(G, 3);
    double s=pow(1+c+sqrt(c*c+2*c), 1.0/3);
    double P=F/(3*pow(s+1/s+1, 2)*G*G);
    double Q=sqrt(1+2*pow(e, 4)*P);
    double r0=-(P*e*e*r)/(1+Q)+sqrt(0.5*a*a*(1+1/Q)-(P*(1-e*e)*z*z)/(Q*(1+Q))+0.5*P*r*r);
    double V=sqrt(pow(r-e*e*r0, 2)+(1-e*e)*z*z);
    double z0=(b*b*z)/(a*V);
    latitude=atan((z+e1*e1*z0)/r);
    latitude*=180/M_PI;
    if(x>=0)
        longitude=atan(y/x);
    else if(y>=0)
        longitude=M_PI+atan(y/x);
    else
        longitude=-M_PI+atan(y/x);
    longitude*=180/M_PI;
    double U=sqrt(pow(r-e*e*r0, 2)+pow(1-e*e, 2)*z*z);
    elevation=U*(1-(b*b)/(a*V));
}
double GeodeticSystemPoint::getLatitude()
{
    return latitude;
}
double GeodeticSystemPoint::getLongitude()
{
    return longitude;
}
double GeodeticSystemPoint::getElevation()
{
    return elevation;
}
