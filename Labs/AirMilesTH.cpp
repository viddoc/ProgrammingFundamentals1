//Tommy Hudson, This is a program to calculate frequent flyer status level.

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int miles, segments;
	string memberStatus;

	//Title
	cout << "Airline Status Calculator\n\n";
	
	//Prompt for segments
	cout << "Please enter number of segments flown: ";
	cin >> segments;
	if (segments < 0)
	{
		cout << "\nError invalid number entered.\n";
		cout << "Please enter number of segments flown: ";
		cin >> segments;
	}

	//Prompt for miles
	cout << "Please enter number of miles flown: ";
	cin >> miles;
	if (miles < 0)
	{
		cout << "\nError invalid number entered.\n";
		cout << "Please enter number of miles flown: ";
		cin >> miles;
	}

	//Find the membership level
	if (miles <= 24999 || segments <=39)
	{
		memberStatus = "Member";
	}
	else if (miles <= 49999 || segments <= 79)
	{
		memberStatus = "Silver";
	}
	else if (miles <= 74999 || segments <= 119)
	{
		memberStatus = "Gold";
	}
	else
	{
		memberStatus = "Platinum";
	}
	
	//Display membership Level
	cout << "\nElite Status: " << memberStatus;
	return 0;
}