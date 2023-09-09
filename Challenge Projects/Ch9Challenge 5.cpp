#include <iostream>

using namespace std;

int doSomething(int* x, int* y) 
{ 
	int temp = *x;
	*x = *y * 10;
	*y = temp * 10;
	return *x + *y;
}

int main()
{
	int x=10, y=2;
	
	cout << "Before calling the function:";
	cout << "\nX = " << x;
	cout << "\nY = " << y;
	
	cout << "\nThe function returns";
	doSomething(&x, &y);
	
	cout << "\nAfter calling the function:";
	cout << "\nX = " << x;
	cout << "\nY = " << y;

	return 0;
}
