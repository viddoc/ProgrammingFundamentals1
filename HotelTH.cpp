//This is a program by Tommy Hudson to calculate rooms in a hotel.
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int main()
{
	int floors, numberRooms, occupiedRooms, floorNumber, unoccupiedRooms, totalOccupiedRooms = 0, totalNumberRooms = 0, totalUnoccupiedRooms = 0;
	float percentOccupied=0.0;
	
	ofstream report;
	report.open("HotelReport.txt");

	//Prompt for # of floors then validate.
	cout << "Hotel Calculator\n";
	cout << "Please enter number of floors in your hotel: ";
	cin >> floors;

	while (floors < 0)
	{
		cout << "\nThere can not be a negative number of floors.\n";
		cout << "Please enter number of floors in your hotel: ";
		cin >> floors;
	}
	report << "********************Hotel Calculator Report********************\n";
	report << "This report shows the occupancy of your hotel that was entered.\n";
	report << "\n\nThe hotel has " << floors << " floors.\n";

	//Prompt for # of rooms on each floor then validate, calculate totals, and ouput to file. 
	for (int count = 1; count <= floors; count++)
	{
		floorNumber = count;
		cout << "\nHow many rooms are on floor " << floorNumber << " : ";
		cin >> numberRooms;
		while (numberRooms < 0)
		{
			cout << "\nThere can not be a negative number of rooms.\n";
			cout << "How many rooms are on floor " << floorNumber << " : ";
			cin >> numberRooms;
		}
		
		cout << "\nHow many rooms are occupied on floor " << floorNumber << " : ";
		cin >> occupiedRooms;
		while (occupiedRooms < 0)
		{
			cout << "\nThere can not be a negative number of rooms.\n";
			cout << "How many rooms are occupied on floor " << floorNumber << " : ";
			cin >> occupiedRooms;
		}
		while (occupiedRooms > numberRooms)
		{
			cout << "\nThere can not be more occupied rooms then total rooms.\n";
			cout << "How many rooms are occupied on floor " << floorNumber << " : ";
			cin >> occupiedRooms;
		}
		unoccupiedRooms = numberRooms - occupiedRooms;
		//Calculate running totals.
		totalNumberRooms += numberRooms;
		totalOccupiedRooms += occupiedRooms;
		totalUnoccupiedRooms += unoccupiedRooms;
		//Output to file each floor 
		report << "Floor " << floorNumber << " Occupied Rooms = " << occupiedRooms << " Uncoccupied Rooms = " << unoccupiedRooms << "\n";

	}
	
	percentOccupied = (static_cast<float>(totalOccupiedRooms) / totalNumberRooms)*100;

	report << "Total Rooms = " << totalNumberRooms;
	report << "\nTotal Occupied Rooms = " << totalOccupiedRooms;
	report << "\nTotal Unoccupied Rooms = " << totalUnoccupiedRooms;
	report << setprecision(2) << fixed << showpoint << "\nPercent of Rooms Occupied = " << percentOccupied << "%";

	report.close();
	return 0;
}