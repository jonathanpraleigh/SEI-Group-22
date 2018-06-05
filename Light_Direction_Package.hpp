/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Light_Direction_Package.hpp
 ** Last Updated by Kaitlin Lynch on 6/4/18
 ** Description: header file for the Light_Direction_Package class. One instance
 should exist for each direction of origin legally possible at an intersection.
 **********************************************************************/

#ifndef Light_Direction_Package_hpp
#define Light_Direction_Package_hpp

#include <stdio.h>
#include "Traffic_Light.hpp"
#include "Speed_Listener.hpp"
#include "Emergency_Listener.hpp"

class Light_Direction_Package
{
private:
    string origin_direction;                                 // direction from which traffic arrives
    class Traffic_Queue left_turn_lane;                      // left turn lane queue
    class Traffic_Light left_turn_light;                     // light for left turn
    class Traffic_Queue center_lane;                         // center lane queue
    class Traffic_Light center_light;                        // light for going straight
    class Traffic_Queue right_turn_lane;                     // right turn lane queue
    class Traffic_Light right_turn_light;                    // light for right turn
    class Speed_Listener speed_listener;                     // speed listener for this direction
    class Emergency_Listener emergency_listener("emergency");// emergency listener for this direction

public:
    Light_Direction_Package();
    Light_Direction_Package(string o, int l, int c, int r);
    void determineHeadingByOriginDirection (string);
};

#endif /* Light_Direction_Package_hpp */
