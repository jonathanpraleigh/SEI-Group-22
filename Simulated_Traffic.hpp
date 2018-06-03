#ifndef SIMULATED_TRAFFIC_HPP
#define SIMULATED_TRAFFIC_HPP
#include <vector>
#include <string>

/*Definitions -- can change.*/
#define SPEED_LIMIT_MIN 20
#define SPEED_LIMIT_MAX 5
#define CLOCK_START 0
#define CLOCK_END 10
#define CARS_MAX 100

/*Variables*/
bool done, em_or_not;
char emergency_vehicles_or_not;
enum Directions { north, east, south, west };
int num_of_cars, num_of_directions, selection;
std::string direction_name, em_or_not_status;
struct option{
	std::string name;
	void(*func_ptr)();
};
struct car_data{
	Directions direction;
	int arrival_time, initial_speed; //assuming a span of definied minutes, arrival time is CLOCK_START + arrival time.
	bool is_emergency_vehicle;
};
std::vector<struct car_data>list_of_cars;


/*Function Prototypes*/
void traffic_simulation_menu();
void randomize_cars(int, int, bool);
void initialize_simulation();
void build_traffic_queue_file();
void exit_simulation();
#endif 
