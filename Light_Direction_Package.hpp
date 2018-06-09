/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Light_Direction_Package.hpp
 ** Last Updated by Kaitlin Lynch on 6/5/18
 ** Description: header file for the Light_Direction_Package class. One instance
 should exist for each direction of origin legally possible at an intersection.
 **********************************************************************/

#ifndef Light_Direction_Package_hpp
#define Light_Direction_Package_hpp

#include <vector>
#include "Traffic_Queue.hpp"
#include "Speed_Listener.hpp"
#include "Emergency_Listener.hpp"

using std::vector;

class Light_Direction_Package : public Speed_Listener, Emergency_Listener
{
private:
    string origin_direction;                                 // direction from which traffic arrives
    vector<class Traffic_Queue*> lanes;                      // pointers to lanes
    class Speed_Listener speed_listener;                     // speed listener for this direction
    class Emergency_Listener emergency_listener;             // emergency listener for this direction

public:
    Light_Direction_Package(): speed_listener(), emergency_listener(){origin_direction = "unknown";};
    Light_Direction_Package (string o, vector<string> l): speed_listener(), emergency_listener()
    {
        origin_direction = o;
        for (string s: l)
            createLane(s);
    };
    void setOriginDirection (string);
    string getOriginDirection ();
    vector<Traffic_Queue*>* getLanes();
    void createLane(string);
    string _determineHeadingByOriginDirection (string);
};

#endif /* Light_Direction_Package_hpp */
