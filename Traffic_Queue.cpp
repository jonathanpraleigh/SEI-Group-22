/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Traffic_Queue.cpp
 ** Last Updated by Kaitlin Lynch on 5/30/18
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
    heading.first = "unknown";
    heading.second = "unknown";
    mode = "unknown";
    total_wait_time = 0;
}


/**********************************************************************
 ** Constructor
 ** Description: sets heading and mode. Sets
 total_wait_time to 0.
 **********************************************************************/
Traffic_Queue::Traffic_Queue(pair<string, string> h, string m){
    heading = h;
    mode = m;
    total_wait_time = 0;
}


int Traffic_Queue::getSize()
{
    return users_in_queue.size();
}


void Traffic_Queue::setHeading(string h1, string h2)
{
    heading.first = h1;
    heading.second = h2;

}


pair<string, string> Traffic_Queue::getHeading()
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


void Traffic_Queue::setTotalWaitTime(double twt)
{
    total_wait_time = twt;
}


double Traffic_Queue::getTotalWaitTime()
{
    return total_wait_time;
}


/**********************************************************************
 ** calcAverageWaitTime
 ** Description: calculates the average wait time for users currently
 in queue
 **********************************************************************/
double Traffic_Queue::calcAverageWaitTime()
{
    return total_wait_time / users_in_queue.size();
}


/**********************************************************************
 ** addUser
 ** Description: adds a User to the back of the queue
 **********************************************************************/
void Traffic_Queue::addUser(class User u)
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
void Traffic_Queue::removeUntilUser(class User u)
{
    while (users_in_queue.front().getId() != u.getId())
    {
        removeUserFromFront();
    }
}
