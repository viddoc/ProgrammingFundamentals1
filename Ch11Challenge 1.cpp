#include <iostream>
#include <string>
#include <locale>
#include <iomanip>

using namespace std;

struct MovieData
{
	string title;
	string director;
	string yearReleased;
	string runningTime;
	long double cost;
	long double revenue;
	long double profit;
};

void displayData(MovieData&);

int main()
{
	MovieData first, second;
	
	first.title = "The Matrix";
	first.director = "The Wachowskis";
	first.yearReleased = "1999";
	first.runningTime = "136 minutes";
	first.cost = 63000000;
	first.revenue = 460000000;
	first.profit = first.revenue - first.cost;

	second.title = "Fight Club";
	second.director = "David Fincher";
	second.yearReleased = "1999";
	second.runningTime = "139 minutes";
	second.cost = 63000000;
	second.revenue = 100000000;
	second.profit = second.revenue - second.cost;

	displayData(first);
	cout << endl;
	displayData(second);

	return 0;

}

void displayData(MovieData& info)
{

	cout << "\nMovie Title: " << info.title;
	cout << "\nMovie Director: " << info.director;
	cout << "\nMovie Released: " << info.yearReleased;
	cout << "\nMovie Run Time: " << info.runningTime;
	cout << "\nMovie Profit: ";
	cout.imbue(locale("en_US.UTF-8"));
	cout << put_money(info.profit * 100);
}