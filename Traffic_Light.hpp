/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Traffic_Light.hpp
 ** Last Updated by Kaitlin Lynch on 6/5/18
 ** Description: header file for the Traffic_Light class. One instance
 should exist for each direction of travel legally possible from a
 given direction of origin in an intersection.
 **********************************************************************/

#ifndef Traffic_Light_hpp
#define Traffic_Light_hpp

#include <stdio.h>
#include <iostream>

using std::string;


class Traffic_Light
{
private:
    string heading;             // direction of travel permitted
    string origin;              // direction of users controlled by light
    string color;               // current color of light
    double time_turned;         // time light turned that color
    
public:
    Traffic_Light();
    Traffic_Light(string h, string o);
    void setHeading(string);
    string getHeading();
    void setOrigin(string);
    string getOrigin();
    void setColor (string);
    string getColor();
    void setTimeTurned(double);
    double getTimeTurned();
    void updateLight (string, double);
    void changeLight(double);
};

#endif /* Traffic_Light_hpp */

