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
 Get Users in Single Queue
 **********************/
    std::ifstream infile("testfile.txt");
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
  
    return 0;

}

