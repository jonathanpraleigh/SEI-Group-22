/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Intersection.hpp
 ** Last Updated by Kaitlin Lynch on 6/4/18
 ** Description: method file for the Intersection class. One instance
 represents one intersection.
 **********************************************************************/

#include "Intersection.hpp"

/**********************************************************************
 ** Default Constructor
 ** Description: all directions default to unknown. Currently needs to be set manually
 **********************************************************************/
Intersection::Intersection()
{
    if (num_intersections < 0)
        num_intersections = 0;
    num_intersections++;
    id = num_intersections;
}

