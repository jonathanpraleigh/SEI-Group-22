/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Light_Direction_Package.cpp
 ** Last Updated by Kaitlin Lynch on 6/4/18
 ** Description: method file for the Light_Direction_Package class. One instance
 should exist for each direction of origin legally possible at an intersection.
 **********************************************************************/

#include "Light_Direction_Package.hpp"

/**********************************************************************
 ** Default Constructor
 ** Description: sets origin direction to unknown
 **********************************************************************/
Light_Direction_Package::Light_Direction_Package()
{
    origin_direction = "unknown";
}


/**********************************************************************
 ** Constructor
 ** Description: sets origin direction. For each lanes (left, center,
 right) with a value > 0, heading of queue and light is updated based
 on direction of origin
 **********************************************************************/
Light_Direction_Package::Light_Direction_Package(string o, int l, int c, int r)
{
    origin_direction = o;
    if (l > 0)
    {
        determineHeadingByOriginDirection("left");
        left_turn_lane.setMode("vehicle");
    }

    if (c > 0)
    {
        determineHeadingByOriginDirection("center");
        center_lane.setMode("vehicle");
    }

    if (r > 0)
    {
        determineHeadingByOriginDirection("right");
        right_turn_lane.setMode("vehicle");
    }
        

}


/**********************************************************************
 ** determineHeadingByOriginDirection
 ** Description: sets the heading for the light and queue of a give lane
 based on the direction of origin
 **********************************************************************/
void Light_Direction_Package::determineHeadingByOriginDirection(string lane)
{
    // set left lane heading
    if (lane.compare("left") == 0)
    switch(origin_direction[0])
    {
        case 'n':
        {
            left_turn_lane.setHeading("east");
            left_turn_light.setHeading("east");
        }
        case 'e':
        {
            left_turn_lane.setHeading("south");
            left_turn_light.setHeading("south");
        }
        case 's':
        {
            left_turn_lane.setHeading("west");
            left_turn_light.setHeading("west");
        }
        case 'w':
        {
            left_turn_lane.setHeading("north");
            left_turn_light.setHeading("north");
        }
    }

    //set center lane heading
    if (lane.compare("center") == 0)
        switch(origin_direction[0])
    {
        case 'n':
        {
            left_turn_lane.setHeading("south");
            left_turn_light.setHeading("south");
        }
        case 'e':
        {
            left_turn_lane.setHeading("west");
            left_turn_light.setHeading("west");
        }
        case 's':
        {
            left_turn_lane.setHeading("north");
            left_turn_light.setHeading("north");
        }
        case 'w':
        {
            left_turn_lane.setHeading("east");
            left_turn_light.setHeading("east");
        }
    }

    //set right lane heading
    if (lane.compare("left") == 0)
        switch(origin_direction[0])
    {
        case 'n':
        {
            left_turn_lane.setHeading("west");
            left_turn_light.setHeading("west");
        }
        case 'e':
        {
            left_turn_lane.setHeading("north");
            left_turn_light.setHeading("north");
        }
        case 's':
        {
            left_turn_lane.setHeading("east");
            left_turn_light.setHeading("east");
        }
        case 'w':
        {
            left_turn_lane.setHeading("south");
            left_turn_light.setHeading("south");
        }
    }

}

