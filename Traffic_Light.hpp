/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Traffic_Light.hpp
 ** Last Updated by Kaitlin Lynch on 6/1/18
 ** Description: header file for the Traffic_Light class. One instance
 should exist for each direction of travel legally possible from a
 given direction of origin in an intersection.
 **********************************************************************/

#ifndef Traffic_Light_hpp
#define Traffic_Light_hpp

#include <stdio.h>
#include "Traffic_Queue.hpp"


class Traffic_Light
{
private:
    pair<string, string> heading;
    string color;
    double time_turned;
    double duration;
    double yellow_duration;
    
public:
    Traffic_Light();
    Traffic_Light(pair<string, string>, string, double, double);
    void setHeading(string, string);
    pair<string, string> getHeading();
    void setColor (string);
    string getColor();
    void setTimeTurned();
    double getTimeTurned();
    void setDuration(double);
    double getDuration();
    void setYellowDuration(double);
    double getYellowDuration();
    void changeLight(double);
};

#endif /* Traffic_Light_hpp */

