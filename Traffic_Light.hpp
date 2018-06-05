/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Traffic_Light.hpp
 ** Last Updated by Kaitlin Lynch on 6/4/18
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
    string heading;             // direction of travel permitted
    string color;               // current color of light
    double time_turned;         // time light turned that color
    double duration;            // how long light should remain color
    double yellow_duration;     // how long light should remain yellow
    
public:
    Traffic_Light();
    Traffic_Light(string, string, double, double);
    void setHeading(string);
    string getHeading();
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

