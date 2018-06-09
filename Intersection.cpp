/**********************************************************************
 ** Project: SEI Group 22
 ** File name: Intersection.hpp
 ** Last Updated by Kaitlin Lynch on 6/5/18
 ** Description: method file for the Intersection class. One instance
 represents one intersection.
 **********************************************************************/

#include "Intersection.hpp"
#include <string>


/**********************************************************************
 ** Default Constructor
 ** Description: sets intersection id. Intersection has no traffic directions.
 **********************************************************************/
Intersection::Intersection()
{
    id = num_intersections();
}

/**********************************************************************
 ** Constructor
 ** Description: creates light direction packages for each direction of
 origin. Each pair should be the origini direction and the vector of lanes
 for the light direction package
 **********************************************************************/
Intersection::Intersection(vector<pair<string,vector<string>>> directions)
{
    id = num_intersections();
    Light_Direction_Package* temp;
    for (pair<string, vector<string>> d : directions)
    {
        temp = new Light_Direction_Package(d.first, d.second);
        origin_directions.push_back(temp);
    }
}


/**********************************************************************
 ** print
 ** Description: prints the intersection
 **********************************************************************/
void Intersection::print()
{
    cout << "Intersection " << id << endl;
    for (Light_Direction_Package* ldp: origin_directions)
    {
        cout << "Traffic originating from the " << ldp->getOriginDirection() << " can travel in the following directions: " << endl;
        for (Traffic_Queue* tq: *ldp->getLanes())
            cout << tq->getHeading() << endl;
    }
}
