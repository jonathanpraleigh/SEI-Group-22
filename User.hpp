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

using std::string;

class User
{
private:
    static int num_users;               // total number users for unique id;
    int id;                            // unique user id;
    string heading;                    // direction user is heading, determined by lane
    string origin		       // direction user is coming from determined by road
    string mode;                       // mode of transportation (e.g., vehicle, pedestrian, bike)
    string type;                       // type of override user (e.g., emergency, public_transport)
    double time_arrived;               // time (seconds) when user detected entering system
    int speed;                         // speed of user when first detected by sensors

public:
    User ();
    User (string h, string o, string m, string t, double ta, int s);
    void setId (int);
    int getId();
    void setHeading (string h);
    string getHeading();
    void setOrigin(string o);
    string getOrigin();
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
