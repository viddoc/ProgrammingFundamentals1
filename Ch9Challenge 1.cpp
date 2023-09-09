#include <iostream>

using namespace std;

int* arrayAllocator(int size)
{
	int* ptr = new int[size];
	return ptr;
}

int main()
{
	
	int* pointer;
	int numberElements;

	cout << "Enter an array size: ";
	cin >> numberElements;
	pointer = arrayAllocator(numberElements);
	
	for (int count = 0; count < numberElements; count++)
	{
		pointer[count] = count;
	}
	cout << "\nValues in the array are as follows:\n";
	for (int count = 0; count < numberElements; count++)
	{
		cout << "Element " << count << " has the value of " << pointer[count] << ".\n";
	}
	delete[] pointer;
	pointer = 0;

	return 0;
}