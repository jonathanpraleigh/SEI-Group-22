/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Traffic_Queue.cpp
 ** Last Updated by Maria Taborda on 6/6/18
 ** Description: method file for the Traffic_Queue class. One instance
 should exist for each direction of travel legally possible from a
 given direction of origin in an intersection.
 **********************************************************************/

#include "Traffic_Queue.hpp"

/**********************************************************************
 ** Default Constructor
 ** Description: sets heading, origin, and mode to unknown. Sets
 total_wait_time to 0.
 **********************************************************************/
Traffic_Queue::Traffic_Queue()
{
    heading = "unknown";
    origin = "unknown";
    mode = "vehicle";
    color ="red";
    time_turned = 0;
}


/**********************************************************************
 ** Constructor
 ** Description: sets heading and origin. Mode defaults to vehicle and color defaults to red.
 **********************************************************************/
Traffic_Queue::Traffic_Queue(string h, string o)
{
    heading = h;
    origin = o;
    mode = "vehicle";
    color ="red";
    time_turned = 0;
}


/**********************************************************************
 ** Constructor
 ** Description: sets heading, origin, and mode. Color still defaults to red.
 **********************************************************************/
Traffic_Queue::Traffic_Queue(string h, string o, string m)
{
    heading = h;
    origin = o;
    mode = m;
    color ="red";
    time_turned = 0;
}


int Traffic_Queue::getSize()
{
    return users_in_queue.size();
}


void Traffic_Queue::setHeading(string h)
{
    heading = h;

}


string Traffic_Queue::getHeading()
{
    return heading;
}

void Traffic_Queue::setOrigin(string o)
{
    origin = o;

}


string Traffic_Queue::getOrigin()
{
    return origin;
}


void Traffic_Queue::setMode(string m)
{
    mode = m;
}


string Traffic_Queue::getMode()
{
    return mode;
}


void Traffic_Queue::setColor (string c)
{
    color = c;
}


string Traffic_Queue::getColor()
{
    return color;
}


/**********************************************************************
 ** addUser
 ** Description: adds a User to the back of the queue
 **********************************************************************/
void Traffic_Queue::addUser(class User &u)
{
    users_in_queue.push_back(u);
    
}


/**********************************************************************
 ** removeUserFromFront
 ** Description: removes a User from the front of the queue (if any)
 **********************************************************************/
void Traffic_Queue::removeUserFromFront()
{
    if (users_in_queue.size() > 0)
        users_in_queue.pop_front();
}


/**********************************************************************
 ** removeUntilUser
 ** Description: removes Users from the front of the queue until a
 specific User is reached.
 **********************************************************************/
void Traffic_Queue::removeUntilUser(class User &u)
{
    while (users_in_queue.front().getId() != u.getId())
    {
        removeUserFromFront();
    }
}


/**********************************************************************
 ** getFirstUserInLine()
 ** Description: returns the first user in the queue as a pointer
 **********************************************************************/
class User* Traffic_Queue::getFirstUserInLine()
{
    return &users_in_queue.front();
}


/**********************************************************************
 ** calcAverageWaitTime
 ** Description: calculates the average wait time for users currently
 in queue
 **********************************************************************/
double Traffic_Queue::calcAverageWaitTime(double current_time)
{
    double total_wait_time = 0;
    for (class User u: users_in_queue)
        total_wait_time += u.calcTimeWaited(current_time);
    return total_wait_time / users_in_queue.size();
}


void Traffic_Queue::setTimeTurned(double t)
{
    time_turned = t;
}


double Traffic_Queue::getTimeTurned()
{
    return time_turned;
}


/**********************************************************************
 ** updateLight
 ** Description: updates the color and time turned of a light
 **********************************************************************/
void Traffic_Queue::updateLight(string c, double t)
{
    color = c;
    time_turned = t;
}


/**********************************************************************
 ** changeLight
 ** Description: changes the color of a light to the next correct color
 ** Update: this currently only changes the lights between green and red
 **********************************************************************/
void Traffic_Queue::changeLight(double t)
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
        // color = "yellow";
        color = "red";
        time_turned = t;
    }
}


