#include "Simulated_Traffic.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <random>
#include <ctime>
#include <limits>
#include <algorithm>

/**********************************************************************
** traffic_simulation_menu
** Description: Handles the menu for the traffic simulation. Pulls
**				from the vector of menu options. Allows for menu
**				expansion for hardcoded test scenarios.
**********************************************************************/

void traffic_simulation_menu()
{
	/*Function Pointers*/
	void(*ptr_initialize_simulation)() = &initialize_simulation;
	void(*ptr_exit_simulation)() = &exit_simulation;


	/*Menu Options*/
	struct option start_simulation = {
		"Create Simulation Data", //option name
		ptr_initialize_simulation //function pointer
	};
	struct option exit_menu = {
		"Exit", //option name
		ptr_exit_simulation // function pointer
	};

	std::vector<struct option>options_vector;
	options_vector.push_back(start_simulation);
	options_vector.push_back(exit_menu);

	done = false;

	while (done == false)
	{
		std::cout << "Options:\n----------\n";

		for (int i = 0; i < options_vector.size(); i++)
		{
			std::cout << "(" << i + 1 << ") " << options_vector[i].name << "\n";
		}

		std::cout << "Selection: ";
		while (!(std::cin >> selection) && selection > options_vector.size() && selection < 1)
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		options_vector[selection - 1].func_ptr();
	}
}

/**********************************************************************
** initialize_simulation
** Description: input for simulation, calls randomize_cars function
**				with input, and builds testing file.
**********************************************************************/


void initialize_simulation()
{
	std::cout << "# of cars: ";
	while (!(std::cin >> num_of_cars) && num_of_cars > CARS_MAX)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "# of approach direction: ";
	while (!(std::cin >> num_of_directions) && num_of_directions > 4 && num_of_directions < 2)
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	std::cout << "Include emergency vehicles(y/n): ";

	do
	{
		std::cin >> emergency_vehicles_or_not;

		if (emergency_vehicles_or_not == 'Y' || emergency_vehicles_or_not == 'y')
		{
			em_or_not = true;
		}

		if (emergency_vehicles_or_not == 'N' || emergency_vehicles_or_not == 'n')
		{
			em_or_not = false;
		}
	} while (emergency_vehicles_or_not != 'Y' && emergency_vehicles_or_not != 'y' && emergency_vehicles_or_not != 'N' && emergency_vehicles_or_not != 'n');

	randomize_cars(num_of_cars, num_of_directions, em_or_not);
	build_traffic_queue_file();
}

/**********************************************************************
** randomize_cars
** Description: builds a car using random values and pushes it into a
**				vector. Then sorts the vector by time arrived.
**********************************************************************/

void randomize_cars(int number_of_cars, int approach_directions, bool emergency_vehicles)
{
	srand(time(NULL));

	for (int i = 0; i < number_of_cars; i++)
	{
		car_data temp;
		temp.arrival_time = rand() % (CLOCK_END - CLOCK_START + 1) + CLOCK_START;
		temp.direction = static_cast<Directions>(rand() % approach_directions + 1);
		temp.initial_speed = rand() % (SPEED_LIMIT_MAX - SPEED_LIMIT_MIN + 1) + SPEED_LIMIT_MIN;
		if (emergency_vehicles == 0)
		{
			temp.is_emergency_vehicle = false;
		}
		else
		{
			if (rand() % 10 > 9)
			{
				temp.is_emergency_vehicle = true;
			}
			else temp.is_emergency_vehicle = false;
		}
		list_of_cars.push_back(temp);
	}
	std::sort(list_of_cars.begin(), list_of_cars.end(), [](car_data const& a, car_data const& b) { return a.arrival_time < b.arrival_time; });
}

/**********************************************************************
** build_traffic_queue_file
** Description: Builds a text file with test data.
**********************************************************************/

void build_traffic_queue_file()
{
	std::ofstream of;
	of.open("testfile.txt", std::ofstream::out | std::ofstream::trunc);

	for (int i = 0; i < list_of_cars.size(); i++)
	{
		of << "Car: " << i << "\n";
		of << "Time: " << list_of_cars[i].arrival_time << "\n";
                if ( list_of_cars[i].direction == 1 )
                {
                        direction_name = "north";
                }
                else if ( list_of_cars[i].direction == 2)
                {
                        direction_name = "east";
                }
                else if ( list_of_cars[i].direction == 3)
                {
                        direction_name = "south";
                }
                else if ( list_of_cars[i].direction == 4)
                {
                        direction_name = "west";
                }

		of << "Direction: " << direction_name << "\n";
		of << "Speed: " << list_of_cars[i].initial_speed << "\n";
		if ( list_of_cars[i].is_emergency_vehicle == true)
		{
			override_type_name = "emergency";
		}
		else { override_type_name = "none"}
		of << "UserType: " << override_type_name << "\n";
	}

	of.close();
}

/**********************************************************************
** exit_simulation
** Description: Updates done variable to exit menu.
**********************************************************************/

void exit_simulation()
{
	done = true;
}


