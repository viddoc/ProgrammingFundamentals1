#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
	const int SIZE = 100;
	char first[SIZE], middle[SIZE], last[SIZE], full[SIZE];

	cout << "Please enter your first name then press enter.\n";
	cin.getline(first, SIZE);
	cout << "Please enter your middle name then press enter.\n";
	cin.getline(middle, SIZE);
	cout << "Please enter your last name then press enter.\n";
	cin.getline(last, SIZE);
	
	strcpy_s(full, last);
	strcat_s(full, ", ");
	strcat_s(full, first);
	strcat_s(full, " ");
	strcat_s(full, last);

	cout << full;

	return 0;

}