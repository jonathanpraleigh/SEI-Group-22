/**********************************************************************
 ** Project: SEI Group 22
 ** File name: User.cpp
 ** Last Updated by Kaitlin Lynch on 5/30/18
 ** Description: method file for the User class. Users will begin as
 vehicles but may also be pedestrians, bikes, public transport, etc.
 in future iterations.
 **********************************************************************/

#include "User.hpp"

/**********************************************************************
 ** Default Constructor
 ** Description: sets heading, mode, and type to unknown. Sets
 time_arrived to current time and sets time_waited to 0.
**********************************************************************/
User::User ()
{
    if (num_users < 1)
        num_users = 0;
    else num_users++;

    id = num_users;
    heading.first = "unknown";
    heading.second = "unknown";
    mode = "unknown";
    type = "unknown";
    time_arrived = clock()/1000;    // clock ticks converted to seconds
}


/**********************************************************************
 ** Testing Constructor
 ** Description: Sets heading, mode, and type. Sets
 time_arrived to current clock time in seconds.
 **********************************************************************/
User::User (pair<string, string> h, string m, string t, int s)
{
    if (num_users < 1)
        num_users = 0;
    else num_users++;
    id = num_users;
    heading = h;
    mode = m;
    type = t;
    time_arrived = clock()/1000;    // clock ticks converted to seconds
    speed = s;
}


/**********************************************************************
 ** Sensor Constructor
 ** Description: Sets heading, mode, and type. Sets
 time_arrived to time first detected by sensor in seconds. Accounts for
 any delay when sending information from sensors to system.
 **********************************************************************/
User::User (pair<string, string> h, string m, string t, double ta, int s)
{
    if (num_users < 1)
        num_users = 0;
    else num_users++;
    id = num_users;
    heading = h;
    mode = m;
    type = t;
    time_arrived = ta;
    speed = s;
}


void User::setId (int n)
{
    id = n;
}


int User::getId()
{
    return id;
}


void User::setHeading (string h1, string h2)
{
    heading.first = h1;
    heading.second = h2;
}


pair<string, string> User::getHeading()
{
    return heading;
}


void User::setMode (string m)
{
    mode = m;
}


string User::getMode()
{
    return mode;
}


void User::setType (string t)
{
    type = t;
}


string User::getType()
{
    return type;
}


void User::setTimeArrived (double ta)
{
    time_arrived = ta;
}


double User::getTimeArrived()
{
    return time_arrived;
}


void User::setSpeed(int s)
{
    speed = s;
}


int User::getSpeed()
{
    return speed;
}


double User::calcTimeWaited()
{
    double current_time = clock() / 1000;
    double time_waited = current_time - time_arrived;

    return time_waited;
}
