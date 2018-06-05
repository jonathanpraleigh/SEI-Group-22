/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Intersection.hpp
 ** Last Updated by Kaitlin Lynch on 6/4/18
 ** Description: header file for the Intersection class. One instance
 represents one intersection.
 **********************************************************************/

#ifndef Intersection_hpp
#define Intersection_hpp

#include <stdio.h>
#include "Light_Direction_Package.hpp"


class Intersection
{
private:
    static int num_intersections;       // total number of intersections
    int id;                             // unique id based on total number of intersections
    class Light_Direction_Package north_light_package;     // north-originating traffic
    class Light_Direction_Package south_light_package;     // south-originating traffic
    class Light_Direction_Package east_light_package;      // east-originating traffic
    class Light_Direction_Package west_light_package;      // west-originating traffic
    
public:
    Intersection();
};

#endif /* Intersection_hpp */
