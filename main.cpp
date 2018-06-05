/**********************************************************************
** Project: SEI Group 22
** File name: main.cpp
** Created by Kaitlin Lynch on 5/29/18 modified 06/03/18
** Contributors: James/Maria
** Description: this is the main method.
**********************************************************************/
#include "User.hpp"
#include "Traffic_Queue.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;


int main(int argc, const char * argv[])
{
	//At this point main is just used to pull in User data and place them in a single traffic queue
	std::ifstream infile("testfile.txt");
	std :: vector<User> allUsers;
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
