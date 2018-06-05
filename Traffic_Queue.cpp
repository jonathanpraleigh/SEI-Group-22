/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Traffic_Queue.cpp
 ** Last Updated by Kaitlin Lynch on 6/4/18
 ** Description: method file for the Traffic_Queue class. One instance
 should exist for each direction of travel legally possible from a
 given direction of origin in an intersection.
 **********************************************************************/

#include "Traffic_Queue.hpp"

/**********************************************************************
 ** Default Constructor
 ** Description: sets heading and mode to unknown. Sets
 total_wait_time to 0.
 **********************************************************************/
Traffic_Queue::Traffic_Queue()
{
    heading = "unknown";
    mode = "unknown";
    total_wait_time = 0;
}


/**********************************************************************
 ** Constructor
 ** Description: sets heading and mode. Sets
 total_wait_time to 0.
 **********************************************************************/
Traffic_Queue::Traffic_Queue(string h, string m){

    heading = h;
    mode = m;
    total_wait_time = 0;
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


void Traffic_Queue::setMode(string m)
{
    mode = m;
}


string Traffic_Queue::getMode()
{
    return mode;
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
 ** Description: removes a User from the front of the queue
 **********************************************************************/
void Traffic_Queue::removeUserFromFront()
{
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
 ** calcAverageWaitTime
 ** Description: calculates the average wait time for users currently
 in queue
 **********************************************************************/
double Traffic_Queue::calcAverageWaitTime()
{
    double total_wait_time = 0;
    for (class User u: users_in_queue)
        total_wait_time += u.calcTimeWaited();
    return total_wait_time / users_in_queue.size();
}
