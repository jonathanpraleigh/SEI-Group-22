/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Traffic_Queue.hpp
 ** Last Updated by Maria Taborda on 6/6/18
 ** Description: header file for the Traffic_Queue class. One instance
 should exist for each direction of travel legally possible from a
 given direction of origin in an intersection.
 **********************************************************************/

#ifndef Traffic_Queue_hpp
#define Traffic_Queue_hpp

#include <deque>
#include "User.hpp"

using std::deque;

class Traffic_Queue
{
private:
    deque<class User> users_in_queue;         // queue of users in lane
    string origin;                            // origin of users
    string heading;                           // direction of travel permitted by lane
    string mode;                              // mode of transportation (e.g. vehicle, pedestrian)
    string color;                             // current color of light
    double time_turned;                       // time light turned that color

public:
    Traffic_Queue();
    // Constructor for heading and origin
    Traffic_Queue(string h, string o);
    // Constructor for heading, origin, and mode
    Traffic_Queue(string h, string o, string m);
    int getSize();
    void setHeading(string);
    string getHeading();
    void setOrigin(string);
    string getOrigin();
    void setMode(string);
    string getMode();
    void setColor (string);
    string getColor();
    void addUser(class User);
    void removeUserFromFront();
    void removeUntilUser(class User&);
    class User* getFirstUserInLine();
    double calcAverageWaitTime (double);
    void setTimeTurned(double);
    double getTimeTurned();
    void updateLight (string, double);
    void changeLight(double);
};

#endif /* Traffic_Queue_hpp */
