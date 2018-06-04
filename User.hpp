/**********************************************************************
 ** Project: SEI Group 22
 ** File name: User.hpp
 ** Last Updated by Kaitlin Lynch on 5/30/18
 ** Description: header file for the User class. Users will begin as
 vehicles but may also be pedestrians, bikes, public transport, etc.
 in future iterations.
 **********************************************************************/

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <iostream>
#include <utility>

using std::string;
using std::pair;

class User
{
private:
    int num_users;              // total number users for unique id;
    int id;                            // unique user id;
    //pair<string, string> heading;      // direction user is heading, determined by lane
    string heading;
    string mode;                       // mode of transportation (e.g., vehicle, pedestrian, bike)
    string type;                       // type of override user (e.g., emergency, public_transport)
    double time_arrived;               // time (seconds) when user detected entering system
    int speed;                         // speed of user when first detected by sensors

public:
    // default constructor
    User ();
    // testing constructor (time_arrived set by system)
    // User (pair<string, string> h, string m, string t, int s);
    User (string h, string m, string t, int s);
    // sensor constructor (time_arrived received from sensors)
    // User (pair<string, string> h, string m, string t, double ta, int s);
    User (string h, string m, string t, double ta, int s);
    void setId (int);
    int getId();
    //void setHeading (string h1, string h2);
    void setHeading (string h);
    //pair<string, string> getHeading();
    string getHeading();
    void setMode (string m);
    string getMode();
    void setType (string t);
    string getType();
    void setTimeArrived (double ta);
    double getTimeArrived();
    void setSpeed(int s);
    int getSpeed();
    double calcTimeWaited();
};

#endif /* User_hpp */
