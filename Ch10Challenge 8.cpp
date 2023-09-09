#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()

{
	const int SIZE = 100;
	char numbers[SIZE], add[1];
	int sum = 0;

	cout << "Enter a series of numbers with no spaces between them: ";
	cin.getline(numbers, SIZE);
	
	for (int count = 0; count < strlen(numbers); count++)
	{
		add[0] = numbers[count];
		sum += atoi(add);
	}

	cout << "The sum of " << numbers << " is " << sum << ".";

	return 0;
}