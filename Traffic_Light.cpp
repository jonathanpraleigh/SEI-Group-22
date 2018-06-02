/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Traffic_Light.cpp
 ** Last Updated by Kaitlin Lynch on 6/1/18
 ** Description: method file for the Traffic_Light class. One instance
 should exist for each direction of travel legally possible from a
 given direction of origin in an intersection.
 **********************************************************************/

#include "Traffic_Light.hpp"

/**********************************************************************
 ** Default Constructor
 ** Description: sets heading to unknown, color to red, time_turned to
 current time (seconds), duration to 0, and yellow_duration to 4 seconds.
 **********************************************************************/
Traffic_Light::Traffic_Light()
{
    heading.first = "unknown";
    heading.second = "unknown";
    color = "red";
    time_turned = clock()/1000;
    duration = 0.0;
    yellow_duration = 4;    // 4 seconds (35 mph)
}


/**********************************************************************
 ** Constructor
 ** Description: sets heading, color, duration, and yellow_duration. Sets
 time_turned to current time.
 **********************************************************************/
Traffic_Light::Traffic_Light(pair<string, string> h, string c, double d, double yd)
{
    heading = h;
    color = c;
    time_turned = clock()/1000;
    duration = d;
    yellow_duration = yd;
}


void Traffic_Light::setHeading(string h1, string h2)
{
    heading.first = h1;
    heading.second = h2;
}


pair<string, string> Traffic_Light::getHeading()
{
    return heading;
}


void Traffic_Light::setColor (string c)
{
    color = c;
}


string Traffic_Light::getColor()
{
    return color;
}


void Traffic_Light::setTimeTurned()
{
    time_turned = clock()/1000;
}


double Traffic_Light::getTimeTurned()
{
    return time_turned;
}


void Traffic_Light::setDuration(double d)
{
    duration = d;
}


double Traffic_Light::getDuration()
{
    return duration;
}


void Traffic_Light::setYellowDuration(double yd)
{
    yellow_duration = yd;
}


double Traffic_Light::getYellowDuration()
{
    return yellow_duration;
}


void Traffic_Light::changeLight(double d)
{
    // light is red
    if (color.compare("red") == 0)
    {
        color = "green";
        time_turned = clock()/1000;
        duration = d;
    }

    //light is yellow
    else if (color.compare("yellow") == 0)
    {
        color = "red";
        time_turned = clock()/1000;
        duration = d;
    }
    // light is green
    else
    {
        color = "yellow";
        time_turned = clock()/1000;
        duration = yellow_duration;
        changeLight(d);
    }
}
