/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Intersection.hpp
 ** Last Updated by Kaitlin Lynch on 6/5/18
 ** Description: header file for the Intersection class. One instance
 represents one intersection.
 **********************************************************************/

#ifndef Intersection_hpp
#define Intersection_hpp

#include <stdio.h>
#include <utility>
#include "Light_Direction_Package.hpp"

using std::pair;
using std::cout;
using std::endl;

class Intersection
{
public:
    static int num_intersections()       // total number of intersections
    {
        static int num_intersections = 0;
        return num_intersections ++;
    }
    int id;                             // unique id based on total number of intersections
    vector<class Light_Direction_Package*> origin_directions; // pointers to light direction packages
    Intersection();
    Intersection (vector<pair<string,vector<string>>>);
    void print();
};

#endif /* Intersection_hpp */
