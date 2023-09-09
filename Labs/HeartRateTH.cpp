//Tommy Hudson program to calculate aerobic training heart rate
#include <iostream>

using namespace std;

int main()
{
	double age, restingHR, THR;
	cout << "Enter your age: ";
	cin >> age;
	cout << "Enter your resting heart rate: ";
	cin >> restingHR;
	THR = .7 * (220 - age) + .3 * restingHR;
	cout << "\nYour THR is " << int(THR) << " beats per minute\n";
		return 0;
}