/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Emergency_Listener.cpp
 ** Last Updated by Kaitlin Lynch on 5/30/18
 ** Description: method file for the Emergency_Listener class. This class
 watches for emergency-type users.
 **********************************************************************/

#include "Emergency_Listener.hpp"


/**********************************************************************
 ** Default Constructor
 ** Description: sets override_type to emergency.
 **********************************************************************/
Emergency_Listener::Emergency_Listener()
{
    override_type = "emergency";
}


/**********************************************************************
 ** Constructor
 ** Description: sets override_type.
 **********************************************************************/
Emergency_Listener::Emergency_Listener(string t)
{
    override_type = t;
}


void Emergency_Listener::setOverrideType (string t)
{
    override_type = t;
}


string Emergency_Listener::getOverrideType ()
{
    return override_type;
}


/**********************************************************************
 ** isEmergency
 ** Description: returns true if the user type matches the override_type
 using string compare to compare values
 **********************************************************************/
bool Emergency_Listener::isEmergency (class User u)
{
    if (u.getType().compare(override_type) == 0)
        return true;
    else return false;
}
