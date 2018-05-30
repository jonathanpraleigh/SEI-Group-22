/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Speed_Listener.cpp
 ** Last Updated by Kaitlin Lynch on 5/30/18
 ** Description: method file for the Speed_Listener class. This class
 watches for speeding users who are unlikely to be able to stop in time.
 **********************************************************************/

#include "Speed_Listener.hpp"

/**********************************************************************
 ** Default Constructor
 ** Description: sets max_speed to 20. This accounts for reactiong time
 stop time, and assumes the user is detected 64 feet from the intersection.
 **********************************************************************/
Speed_Listener::Speed_Listener ()
{
    max_speed = 20;
}


/**********************************************************************
 ** Constructor
 ** Description: sets max_speed.
 **********************************************************************/
Speed_Listener::Speed_Listener (int s)
{
    max_speed = s;
}


void Speed_Listener::setMaxSpeed (int s)
{
    max_speed = s;
}


int Speed_Listener::getMaxSpeed ()
{
    return max_speed;
}


/**********************************************************************
 ** isSpeeding
 ** Description: returns true if the user's speed is greater than or
 equal to the max_speed, indicating the user will be unable to stop in time.
 **********************************************************************/
bool Speed_Listener::isSpeeding (class User u)
{
    if (u.getSpeed() >= max_speed)
        return true;
    else return false;
}
