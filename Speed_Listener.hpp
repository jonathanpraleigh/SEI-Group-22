/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Speed_Listener.hpp
 ** Last Updated by Kaitlin Lynch on 6/4/18
 ** Description: header file for the Speed_Listener class. This class
 watches for speeding users who are unlikely to be able to stop in time.
 **********************************************************************/

#ifndef Speed_Listener_hpp
#define Speed_Listener_hpp

#include "User.hpp"

class Speed_Listener
{
private:
    int max_speed;      // max speed at which user can stop once detected

public:
    Speed_Listener ();
    Speed_Listener (int);
    void setMaxSpeed (int);
    int getMaxSpeed ();
    bool isSpeeding (class User);
};

#endif /* Speed_Listener_hpp */
