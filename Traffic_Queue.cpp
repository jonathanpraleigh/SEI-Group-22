//
//  Traffic_Queue.cpp
//  SEI Group 22
//
//  Created by Kaitlin Lynch on 5/29/18.
//  Copyright © 2018 Kaitlin Lynch. All rights reserved.
//

#include "Traffic_Queue.hpp"
Traffic_Queue::Traffic_Queue()
{
    heading.first = "unknown";
    heading.second = "unknown";
    mode = "unknown";
    total_wait_time = 0;
}


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
    heading.second = h2

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


double Traffic_Queue::calcAverageWaitTime()
{
    return total_wait_time / users_in_queue.size();
}


void Traffic_Queue::addUser(class User u)
{
    users_in_queue.push_back(u);
}


void Traffic_Queue::removeUserFromFront()
{
    users_in_queue.pop_front();
}


void Traffic_Queue::removeUntilUser(class User u)
{
    while (users_in_queue.front().getId() != u.getId())
    {
        removeUserFromFront();
    }
}


class User Traffic_Queue::getFirstUserInLine()
{
    return users_in_queue.front();
}
