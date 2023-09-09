//Program to calculate markup on retail items
#include <iostream>
#include <iomanip>

using namespace std;

float calculateRetail(float markup, float wholesaleCost)
{
	float retailPrice;
	retailPrice = ((markup / 100) * wholesaleCost) + wholesaleCost;
	return retailPrice;
}
	int main()
{
	float markup, retailPrice, wholesaleCost;
	
	//Find wholesale cost and validate input
	cout << "Enter the wholesale cost of item: ";
	cin >> wholesaleCost;
	while (wholesaleCost < 0)
	{
		cout << "Cost can not be negative!\n";
		cout << "Enter the wholesale cost of item: ";
		cin >> wholesaleCost;

	}
	
	//Find markup percentage and validate input
	cout << "Enter percentage you wish to markup item by: ";
	cin >> markup;
	while (markup < 0)
	{
		cout << "Percentage can not be negative!\n";
		cout << "Enter percentage you wish to markup item by: ";
		cin >> markup;
	}
	 //Find retail price by calling calculateRetail function
	retailPrice = calculateRetail(markup,wholesaleCost);
	cout << "Retail Price should be: $" << setprecision(2) << showpoint << fixed << retailPrice;
	return 0;
}