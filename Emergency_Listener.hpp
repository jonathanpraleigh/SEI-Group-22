/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Emergency_Listener.hpp
 ** Last Updated by Kaitlin Lynch on 6/4/18
 ** Description: header file for the Emergency_Listener class. This class
 watches for emergency-type users.
 **********************************************************************/

#ifndef Emergency_Listener_hpp
#define Emergency_Listener_hpp

#include <iostream>
#include "User.hpp"

using std::string;

class Emergency_Listener
{
private:
    string override_type;   // type of override, usually "emergency"

public:
    Emergency_Listener();
    Emergency_Listener(string);
    void setOverrideType (string);
    string getOverrideType ();
    bool isEmergency (class User);
};

#endif /* Emergency_Listener_hpp */
