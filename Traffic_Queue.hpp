/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Traffic_Queue.hpp
 ** Last Updated by Kaitlin Lynch on 6/1/18
 ** Description: header file for the Traffic_Queue class. One instance
 should exist for each direction of travel legally possible from a
 given direction of origin in an intersection.
 **********************************************************************/

#ifndef Traffic_Queue_hpp
#define Traffic_Queue_hpp

#include <stdio.h>
#include <deque>
#include "User.hpp"

using std::deque;

class Traffic_Queue
{
private:
    deque<class User> users_in_queue;
    // pair<string, string> heading;
    string heading;
    string mode;
    double total_wait_time;

public:
    Traffic_Queue();
    //Traffic_Queue(pair<string, string> h, string m);
    Traffic_Queue(string h, string m);
    int getSize();
    //void setHeading(string, string);
    void setHeading(string);
    //pair<string, string> getHeading();
    string getHeading();
    void setMode(string);
    string getMode();
    void setTotalWaitTime(double);
    double getTotalWaitTime();
    double calcAverageWaitTime();
    void addUser(class User&);
    void removeUserFromFront();
    void removeUntilUser(class User&);
    class User* getFirstUserInLine();
};

#endif /* Traffic_Queue_hpp */
