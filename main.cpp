 /**********************************************************************
 ** Project: SEI Group 22
 ** File name: main.cpp
 ** Last upadted by Kaitlin Lynch & Maria Taborda on 6/6/18
 ** Description: this is the main method.
 **********************************************************************/

#include <iostream>
#include <assert.h>
#include <fstream>
#include "Intersection.hpp"

using namespace std;

double CURRENT_TIME;
const double MAX_WAIT_TIME = 10;        // 10 time steps

/**********************************************************************
 ** isConflict
 ** Description: returns true if two queues are
 not in conflict, else returns false.
 **********************************************************************/

bool isConflict (Traffic_Queue* tq1, Traffic_Queue* tq2)
{
    // compare origin of first user in first queue with heading from second queue and vise versa
    // East -> West & West -> East
    // South -> East & East -> South
    // South -> West & West -> South
    if (tq1->getOrigin().compare(tq2->getHeading()) == 0 && tq2->getOrigin().compare(tq1->getHeading())== 0)
        return false;
    // otherwise, compare directions of origin. Two lanes originating from the same direction can go
    // at the same time.
    else if (tq1->getOrigin().compare(tq2->getOrigin()) == 0)
        return false;

    // The two lanes are in conflict and cannot go at the same time.
    else return true;

}


/**********************************************************************
 ** changeLightsInIntersection
 ** Description: takes a pointer to an intersection and the lane that should
 be green and updates the lights in the intersection such that that lane and
 its parallel are green and the other lights are red.
 ** Precondition: light for lane is not currently green
 **********************************************************************/
void changeLightsInIntersection (Intersection* T, Traffic_Queue* tq1)
{
    // Confirm direction not green
    assert (tq1->getColor().compare("green") != 0);


    for (Light_Direction_Package* ldp: T->origin_directions)
    {
        Traffic_Queue* temp = NULL;
        for (Traffic_Queue* ptq: *ldp->getLanes())
        {
            // If this queue is not the input queuque and does not conflict
            // with the input queue, save it to temp
            if (ptq != tq1 && !isConflict(ptq, tq1))
                temp = ptq;

            // else if light is not red, change light
            else
            {
                if (ptq->getColor().compare("red") != 0)
                    ptq->changeLight(CURRENT_TIME);
            }

            // otherwise, let light remain red
        }

        // now that all conflicting lights are red, make non-conflicting lanes green
        // every lane does not conflict with at least one other lane
        // still, this ensures we are not dereferencing a null pointer
        assert (temp != NULL);
        // check temp is not already green
        if (temp->getColor().compare("green") != 0)
            temp->changeLight(CURRENT_TIME);
        tq1->changeLight(CURRENT_TIME);
    }
}


/**********************************************************************
 ** changeLightsInIntersection
 ** Description: takes a pointer to an intersection and the two lanes that should
 be green and updates the lights in the intersection such that that the two lanes are green and the
 other lights are red.
 ** Precondition: lights are not in conflict.
 **********************************************************************/
void changeLightsInIntersection (Intersection* T, Traffic_Queue* tq1, Traffic_Queue* tq2)
{
    // Confirm directions are not in conflict
    assert (!isConflict(tq1, tq2));

    for (Light_Direction_Package* ldp: T->origin_directions)
    {
        for (Traffic_Queue* ptq: *ldp->getLanes())
        {
            // If this queue is not not an input queuque, turn the color to red
            if (ptq != tq1 && ptq != tq2)
            {
                if (ptq->getColor().compare("red") != 0)
                    ptq->changeLight(CURRENT_TIME);
                // otherwise, let light remain red
            }
        }

        // now that all conflicting lights are red, turn non-conflicting lanes to green
        // check each if not already green before changing
        if (tq1->getColor().compare("green") != 0)
            tq1->changeLight(CURRENT_TIME);
        if (tq2->getColor().compare("green") != 0)
            tq2->changeLight(CURRENT_TIME);
    }
}


int main(int argc, const char * argv[])
{
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

    // Set up the file stream
    ifstream infile;
    // Check file was opened successfully
    try
    {
        infile.open("testfile.txt");
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
        /******************************
         JAMES & JON
         *****************************/
            // add Users whose time matches current time << JAMES & JON
                // if time car arrives = CURRENT_TIME
                // Create new user for car
                // add user to correct queue
                // We kept the old read in code at the bottom if you want to reuse parts of it
                // Please delete the old code when you are finished
            // END INPUT

        // Create a list of queues that have at least 1 user
        vector <Traffic_Queue*> queues_with_users;

        // For each direction of approaching traffic
        for (Light_Direction_Package* ldp: T_style.origin_directions)
        {
            // For each lane approaching from the same direction
            for (Traffic_Queue* tq: *ldp->getLanes())
            {
                // if there are users in the queue
                if (tq->getSize() > 0)
                    // Add Traffic Queue to list of queues with users
                    queues_with_users.push_back(tq);
            }
        }

        // CASE 1: users exist in only one lane
        if (queues_with_users.size() == 1)
        {
            // if light is not green
            if(queues_with_users[0]->getColor().compare("green") != 0)
            {
                // call light change function to turn light green
                // for this direction and a nonconflicting direction
                changeLightsInIntersection(&T_style, queues_with_users[0]);
            }
        }

        // CASE 2: users exist in only non-conflicting directions (e.g., East and West)
       else if (queues_with_users.size() == 2)
       {
           // if two lanes are not in conflict
           if (!isConflict (queues_with_users[0], queues_with_users[1]))
           {
               // call light change function to ensure both are green
               changeLightsInIntersection(&T_style, queues_with_users[0], queues_with_users[1]);
           }
       }

        // CASE 3: users exist in conflicting directions
        else if (queues_with_users.size() >= 2)
        {
            // First, check if the first user in any queue has been waiting
            // longer than the max wait time
            for (Traffic_Queue* tq: queues_with_users)
            {
                if (tq->getFirstUserInLine()->calcTimeWaited(CURRENT_TIME) >= MAX_WAIT_TIME)
                {
                    // If a wait time reaches the max, that light must turn green next
                    changeLightsInIntersection(&T_style, tq);
                    // stop search once one is found - others will be found next time step
                    break;
                }
            }

            // If no user has been waiting too long, decide which queue(s) receive green lights by finding the two queues not in conflict with the most users between them
            int max = 0;
            int index_q1 = -1;
            int index_q2 = -1;
            for (int i = 0; i < queues_with_users.size() - 1; i++)
            {
                for (int j = i; j < queues_with_users.size(); j++ )
                {
                    if (queues_with_users[i]->getSize() + queues_with_users[j]->getSize() > max && !isConflict(queues_with_users[i], queues_with_users[j]))
                    {
                        // their sum is the new max
                        max = queues_with_users[i]->getSize() + queues_with_users[j]->getSize();

                        // store them so we know which lights to change
                        index_q1 = i;
                        index_q2 = j;
                    }
                }
            }

            // assert indexes are valid before using
            assert (index_q1 >= 0 && index_q1 < queues_with_users.size());
            assert (index_q2 >= 0 && index_q2 < queues_with_users.size());
            // change the lights of the two non-conflicting lanes with the most users between them
            changeLightsInIntersection(&T_style, queues_with_users[index_q1], queues_with_users[index_q2]);
        }

        // GREEN LIGHT: it's time to let users with a green light pass through the intersection
        // currently, we are allowing one user per green light per time step
        // update queues with green lights to remove the first user in line.
        for (Light_Direction_Package* ldp: T_style.origin_directions)
        {
            for (Traffic_Queue* tq: *ldp->getLanes())
            {
                // If the lane has a green light, remove first user in line
                if (tq->getColor().compare("green") == 0)
                    tq->removeUserFromFront();
            }
        }

        // increment time
        CURRENT_TIME++;
    }

    // Close input file
    infile.close();

    /******************************
     JAMES & JON
     *****************************/
    // Output results to file

    /**********************
     OLD CODE: Get Users in Single Queue
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

