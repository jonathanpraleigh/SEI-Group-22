/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Traffic_Light.cpp
 ** Last Updated by Kaitlin Lynch on 6/5/18
 ** Description: method file for the Traffic_Light class. One instance
 should exist for each direction of travel legally possible from a
 given direction of origin in an intersection.
 **********************************************************************/

#include "Traffic_Light.hpp"

/**********************************************************************
 ** Default Constructor
 ** Description: sets heading and origin to unknown, color to red, time_turned to
 current time (seconds).
 **********************************************************************/
Traffic_Light::Traffic_Light()
{
    heading = "unknown";
    origin = "unknown";
    color = "red";
    time_turned = clock()/1000;
}


/**********************************************************************
 ** Constructor
 ** Description: sets heading. Color defaults to red.
 **********************************************************************/
Traffic_Light::Traffic_Light(string h, string o)
{
    heading = h;
    origin = o;
    color = "red";
    time_turned = 0;
}


void Traffic_Light::setHeading(string h)
{
    heading = h;
}


string Traffic_Light::getHeading()
{
    return heading;
}


void Traffic_Light::setOrigin(string o)
{
    origin = o;
}


string Traffic_Light::getOrigin()
{
    return origin;
}


void Traffic_Light::setColor (string c)
{
    color = c;
}


string Traffic_Light::getColor()
{
    return color;
}


void Traffic_Light::setTimeTurned(double t)
{
    time_turned = t;
}


double Traffic_Light::getTimeTurned()
{
    return time_turned;
}


/**********************************************************************
 ** updateLight
 ** Description: updates the color and time turned of a light
 **********************************************************************/
void Traffic_Light::updateLight(string c, double t)
{
    color = c;
    time_turned = t;
}


/**********************************************************************
 ** changeLight
 ** Description: changes the color of a light to the next correct color
 **********************************************************************/
void Traffic_Light::changeLight(double t)
{
    // light is red
    if (color.compare("red") == 0)
    {
        color = "green";
        time_turned = t;
    }

    //light is yellow
    else if (color.compare("yellow") == 0)
    {
        color = "red";
        time_turned = t;
    }

    // light is green
    else
    {
        color = "yellow";
        time_turned = t;
    }
}
