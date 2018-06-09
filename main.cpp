 /**********************************************************************
 ** Project: SEI Group 22
 ** File name: main.cpp
 ** Last upadted by Kaitlin Lynch & James Palen on 6/8/18
 ** Description: this is the main method.
 **********************************************************************/

#include <iostream>
#include <assert.h>
#include <fstream>
#include "Intersection.hpp"
#include <string>

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

    // increment time
    CURRENT_TIME++;

    for (Light_Direction_Package* ldp: T->origin_directions)
    {
        if (ldp->getOriginDirection().compare(tq1->getOrigin()))
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
            if (temp != NULL)
            {
                if (temp->getColor().compare("green") != 0)
                    temp->changeLight(CURRENT_TIME);
            }
            tq1->changeLight(CURRENT_TIME);
        }
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

    // increment time
    CURRENT_TIME++;

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
    /****************************
     Variables to hold test data
     *****************************/
    int carsDeparted = 0;
    int carsArrived = 0;

    /**********************
     Create T intersection
     **********************/
    vector<pair<string,vector<string>>> temp_intersection;

    // South Direction
    pair<string, vector<string>> south;
    south.first = "south";
    south.second.push_back("center");
    south.second.push_back("right");
    temp_intersection.push_back(south);

    // East Direction
    pair<string, vector<string>> east;
    east.first = "east";
    east.second.push_back("left");
    east.second.push_back("right");
    temp_intersection.push_back(east);

    // North Direction
    pair<string, vector<string>> north;
    north.first = "north";
    north.second.push_back("center");
    north.second.push_back("left");
    temp_intersection.push_back(north);

    // Create the intersection
    Intersection T_style(temp_intersection);

    // Print for debugging
    T_style.print();

    /**********************
     READ IN SENSOR DATA
     **********************/
    CURRENT_TIME = 1;

    // Set up the file stream
    ifstream infile;
    // Check file was opened successfully
    try
    {
        // For Kaitie's lazy local testing
        //infile.open("/Users/kaitlinlynch/test_5car_2dir_noEm.txt");
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
        int id, time, speed;
        string heading, origin, type;

        //User tempUser;
        // First line of each user is ID
        //tempUser.setId(stoi(variable));
        id = stoi(variable);
        // Advance line
        infile >> descriptor >> variable;
        // Second line is time arrived
        //tempUser.setTimeArrived(stod(variable));
        time = stoi(variable);
        // Advance line
        infile >> descriptor >> variable;
        //Third line is intended Direction
       // tempUser.setHeading(variable);
        heading = variable;
        // Advance line
        infile >> descriptor >> variable;
        // Fourth line is direction of origin
        // tempUser.setOrigin(variable);
        origin = variable;
        // Advance line
        infile >> descriptor >> variable;
        //Fifth line is user Speed
        //tempUser.setSpeed(stoi(variable));
        speed = stoi(variable);
        // Advance line
        infile >> descriptor >> variable;
        //if the descriptor is Emergency then we know that our user is relevant and has all the appropriate information
        //tempUser.setType(variable);
        type = variable;

        User tempUser(heading, origin, "vehicle", type, time, speed);

        // If the user's time matches the current time, place them in the correct queue
        if (tempUser.getTimeArrived() == CURRENT_TIME)
        {
            // For each direction of approaching traffic
            for (Light_Direction_Package* ldp : T_style.origin_directions)
            {
                // For each lane approaching from the same direction
                for (Traffic_Queue* tq : *ldp->getLanes())
                {
                    // if this is the correct queue
                    if (tq->getHeading().compare(tempUser.getHeading()) == 0 && tq->getOrigin().compare(tempUser.getOrigin()) == 0)
                    {
                        // Add Traffic Queue to list of queues with users
                        tq->addUser(tempUser);
                        // Increment user arrived count for testing purposes.
                        carsArrived++;
                    }
                }
            }
        }

        // if the user's time is later, it's time to run the light cycle and "catch up"
        else if (tempUser.getTimeArrived() != CURRENT_TIME )
        {
            // Create a list of queues that have at least 1 user
            vector <Traffic_Queue*> queues_with_users;

            // For each direction of approaching traffic
            for (Light_Direction_Package* ldp : T_style.origin_directions)
            {
                // For each lane approaching from the same direction
                for (Traffic_Queue* tq : *ldp->getLanes())
                {
                    // if there are users in the queue
                    if (tq->getSize() > 0)
                    {
                        // Add Traffic Queue to list of queues with users
                        queues_with_users.push_back(tq);
                    }
                }
            }

            // CASE 1: users exist in only one lane
            if (queues_with_users.size() == 1)
            {
                // if light is not green
                if (queues_with_users[0]->getColor().compare("green") != 0)
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
                if (!isConflict(queues_with_users[0], queues_with_users[1]))
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
                for (Traffic_Queue* tq : queues_with_users)
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
                    for (int j = i; j < queues_with_users.size(); j++)
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
                assert(index_q1 >= 0 && index_q1 < queues_with_users.size());
                assert(index_q2 >= 0 && index_q2 < queues_with_users.size());
                // change the lights of the two non-conflicting lanes with the most users between them
                changeLightsInIntersection(&T_style, queues_with_users[index_q1], queues_with_users[index_q2]);
            }

            // GREEN LIGHT: it's time to let users with a green light pass through the intersection
            // currently, we are allowing one user per green light per time step
            // update queues with green lights to remove the first user in line.
            for (Light_Direction_Package* ldp : T_style.origin_directions)
            {
                for (Traffic_Queue* tq : *ldp->getLanes())
                {
                    // If the lane has a green light, remove first user in line
                    if (tq->getColor().compare("green") == 0 && tq->getSize() > 0)
                    {
                        tq->removeUserFromFront();
                        // Increment user departed count for test purposes.
                        carsDeparted++;
                    }
                }
            }
        }

    }
    // Close input file
    infile.close();

    cout << "Time Elapsed: " << CURRENT_TIME << endl;
    cout << "Users entering intersection: " << carsArrived << endl;
    cout << "Users exiting intersection: " << carsDeparted << endl;
        return 0;
}
