//Program to determine highest sales
#include <iostream>
#include <string>

using namespace std;

double getSales(string);
void findHighest(double, double, double, double, string, string, string, string);

int main()
{
	string division1 = "Northwest", division2 = "Northeast", division3 = "Southwest", division4 = "Southeast";
	double sales1, sales2, sales3, sales4;
	
	sales1 = getSales(division1);
	sales2 = getSales(division2);
	sales3 = getSales(division3);
	sales4 = getSales(division4);
	findHighest(sales1, sales2, sales3, sales4, division1, division2, division3, division4);
}

double getSales(string division)
{
	double sales = 0.0;
	cout << "What are the quarterly sales for " << division << " division: $ ";
	cin >> sales;
	while (sales < 0)
	{
		cout << "Sales can not be negative.\n";
		cout << "What are the quarterly sales for " << division << " division: $ ";
		cin >> sales;
	}
	return sales;
}

void findHighest(double div1, double div2, double div3, double div4, string nw, string ne, string sw, string se)
{
	if (div1 >= div2 && div1 >= div3 && div1 >= div4)
		cout << nw << " has the largest sales with $" << div1;
	if (div2 >= div1 && div2 >= div3 && div2 >= div4)
		cout << ne << " has the largest sales with $" << div2;
	if (div3 >= div1 && div3 >= div2 && div3 >=div4)
		cout << sw << " has the largest sales with $" << div3;
	if (div4 >= div1 && div4 >= div2 && div4 >= div3)
		cout << se << " has the largest sales with $" << div4;
}