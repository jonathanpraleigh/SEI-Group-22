 /**********************************************************************
 ** Project: SEI Group 22
 ** File name: main.cpp
 ** Last upadted by Kaitlin Lynch on 6/5/18
 ** Description: this is the main method.
 **********************************************************************/

#include <iostream>
#include <fstream>
#include "Intersection.hpp"

using namespace std;

double CURRENT_TIME;
const double MAX_WAIT_TIME = 10;        // 10 time steps

/**********************************************************************
 ** isConflict
 ** Description: returns true if two queues from different origins are
 not in conflict, else returns false.
 ** Preconditions: two queues do not have same origin (function does not
 check).
 **********************************************************************/

bool isConflict (Traffic_Queue* tq1, Traffic_Queue* tq2)
{
    // compare origin of first user in first queue with heading from second queue and vise versa
    // East -> West & West -> East
    // South -> East & East -> South
    // South -> West & West -> South
    if (tq1->getOrigin().compare(tq2->getHeading()) == 0 && tq2->getOrigin().compare(tq1->getHeading()== 0)
        return true;
    else return false;
}

int main(int argc, const char * argv[]) {
/**********************
 Create T intersection
 **********************/
    vector<pair<string,vector<string>>> temp_intersection;

// South Direction
    pair<string, vector<string>> south;
    south.first = "south";
    south.second.push_back("left");
    south.second.push_back("right");
    temp_intersection.push_back(south);

// East Direction
    pair<string, vector<string>> east;
    east.first = "east";
    east.second.push_back("left");
    east.second.push_back("center");
    temp_intersection.push_back(east);

// West Direction
    pair<string, vector<string>> west;
    west.first = "west";
    west.second.push_back("center");
    west.second.push_back("right");
    temp_intersection.push_back(west);

// Create the intersection
    Intersection T_style(temp_intersection);

// Print for debugging
    T_style.print();


/**********************
 Set up Strategy
 **********************/
    CURRENT_TIME = 0;

    // Check file was opened successfully
    try
    {
        ifstream infile("testfile.txt");
        if (!infile)
            throw "File could not be opened.";
    }
    catch (const char* error)
    {
        cerr << error << endl;
    }

    // while there are users in the file
    string descriptor, variable;
    while (infile >> descriptor >> variable)
    {
        // add Users whose time matches current time << JAMES & JON
            // if time  = CURRENT_TIME
            // Create new user
            // add user to correct queue
        // if only parallel queuqes have users, light should be green << no one should stop
        // vecotr of queues whose size > 0
        //if vector.size == 2 && same direction or no conflict, then green

        // Create a list of queues that have at least 1 user
        vector <pair<Traffic_Queue*, Traffic_Light*>> queues_with_users;
        int i = 0;  // iterator
        for (Light_Direction_Package* ldp: T_style.origin_directions)
        {
            for (Traffic_Queue* tq: *ldp->getLanes())
            {
                pair<Traffic_Queue*, Traffic_Light*> temp;
                // if there are users in the queue
                if (tq->getSize() > 0)
                {
                    temp.first = tq;
                    temp.second = *ldp->getLanes()[i];
                }
                i++;
            }
        }

        // if only 2 lanes or less have users
       if (queues_with_users.size() <= 2)
       {
           // if 2 && no conflict, green
           // if 1 green
           if (queues_with_users.size() == 1)
           {
               for (Light_Direction_Package* ldp: T_style.origin_directions)
               {
                   if (ldp->getLights
               }
           }
               
               
       }

        bool flag = "true";
            // iterate through all queues, if conflict set flag to false
            // for each Queue in the list of queues, if size > 0, check for conflict
        // if no conflict
        if (flag)
            

        // if conflict, check wait time, turn green if wait time > max
        // update queues (1 car per time step)
            // for each queue in the list, if size > 0, remove 1 user
        // increment time
        CURRENT_TIME++;
    }



/**********************
 Get Users in Single Queue
 **********************

    vector<User> allUsers;
    User tempUser;


    std::string a, b;
    while(infile >> a >> b)
    {
        User tempUser;
        //a = descriptor
        //b = variable
        //Adjust appropriate variable based on the descriptor that was read in.
        if (a ==  "Car:")
        {
            tempUser.setId(stoi(b));
        }
        else if (a == "Time:")
        {
            tempUser.setTimeArrived(stod(b));

        }
        else if (a == "Direction:")
        {
            tempUser.setHeading(b);
        }
        else if (a == "Speed:")
        {
            tempUser.setSpeed(stoi(b));
        }
        else if (a == "Emergency:")
        {
            tempUser.setType(b);
            allUsers.push_back(tempUser);
        }


    }
    //Will have to create more traffic queues and expand logic when more directions are added.
    Traffic_Queue newWestTQ;
    newWestTQ.setHeading(allUsers[0].getHeading());

    for (int i = 0; i < allUsers.size(); i++)
    {
        if (allUsers[i].getHeading() == "west")
        {
            newWestTQ.addUser(allUsers[i]);
        }
    }
 */
    return 0;

}

