/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Light_Direction_Package.cpp
 ** Last Updated by Kaitlin Lynch on 6/5/18
 ** Description: method file for the Light_Direction_Package class. One instance
 should exist for each direction of origin legally possible at an intersection.
 **********************************************************************/

#include "Light_Direction_Package.hpp"

void Light_Direction_Package::setOriginDirection (string od)
{
    origin_direction = od;
}


string Light_Direction_Package::getOriginDirection ()
{
    return origin_direction;
}


/**********************************************************************
 ** getLanes
 ** Description: returns a pointer to the list of lanes
 **********************************************************************/
vector<Traffic_Queue*>* Light_Direction_Package::getLanes()
{
    return &lanes;
}


/**********************************************************************
 ** getLights
 ** Description: returns a pointer to the list of lights
 **********************************************************************/
vector<Traffic_Light*>* Light_Direction_Package::getLights()
{
    return &lights;
}


/**********************************************************************
 ** createLaneAndLight
 ** Description: creates the lane and light for a given direction (i.e.,
 left, center, right).
 **********************************************************************/
void Light_Direction_Package::createLaneAndLight(string lane)
{
    Traffic_Queue* temp_lane;
    Traffic_Light* temp_light;
    string heading = _determineHeadingByOriginDirection(lane);
    temp_lane = new Traffic_Queue(heading, origin_direction);
    temp_light = new Traffic_Light(heading, origin_direction);
    lanes.push_back(temp_lane);
    lights.push_back(temp_light);
}


/**********************************************************************
 ** _determineHeadingByOriginDirection
 ** Description: returns the heading for the light and queue of a give lane
 based on the direction of origin.
 **********************************************************************/
string Light_Direction_Package::_determineHeadingByOriginDirection(string lane)
{
    // set left heading
    if (lane.compare("left") == 0)
    switch(origin_direction[0])
    {
        case 'n':
        {
            return "east";
        }
        case 'e':
        {
            return "south";
        }
        case 's':
        {
            return "west";
        }
        case 'w':
        {
            return "north";
        }
    }

    //set center/straight heading
    if (lane.compare("center") == 0)
        switch(origin_direction[0])
    {
        case 'n':
        {
            return "south";
        }
        case 'e':
        {
            return "west";
        }
        case 's':
        {
            return "north";
        }
        case 'w':
        {
            return "east";
        }
    }

    //set right heading
    if (lane.compare("right") == 0)
        switch(origin_direction[0])
    {
        case 'n':
        {
            return "west";
        }
        case 'e':
        {
            return "north";
        }
        case 's':
        {
            return "east";
        }
        case 'w':
        {
            return "south";
        }
    }

    // if we reach here, the heading is unknown
    return "unknown";
}

