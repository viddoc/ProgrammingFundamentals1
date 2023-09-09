//Tommy Hudson program to sell lift tickets to user.
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

//Struct for holding customer data.
struct Customer
{
	int number=0;
	string name;
	double cost=0.00;
	int age=0;
	int weekends=0;
	int seasonPass=0;
	int weekdays=0;
	int totalDays=0;
	double discountPercentage = 0.00;
	double discount = 0.00;

};
//Function prototypes.
void introduction();
void informationMenu(const double, const double, const double, const double, const double);
void getCustomerInfo(Customer&);
void purchaseMenu(Customer&);
void findCost(const double, const double, const double, const double, const double, Customer&);
void writeInvoice(ofstream&, Customer&);
int validatePasses(int,Customer&);
int validateMenu(int);
char validateAnswer(char);
void discountMenu(const double, const double);
void priceMenu(const double, const double, const double);

//Main function.
int main()
{
	//Create dynamically allocated array.
	int size;
	Customer* info = nullptr;
	//Constant variables for pass prices.
	const double WEEKDAY = 109.00, WEEKEND = 149.00, SEASON = 899.00, AGE_DISCOUNT=.25, MULTI_DISCOUNT=.15;
	double finalCost=0;
	//Open file and validate
	ofstream invoice;
	invoice.open("Invoice.txt");
	if (!invoice)
	{
		cout << "Error! Please restart the program.";
	}
	//Start invoice and create columns.
	invoice << "\t\t\t\tGreen Oaks Resort Invoice\n"
		<< "====================================================================================\n"
		<< internal << "\t\t\t\t    Passes" << "\t\t  Discount\n"
		<< left << setw(5) << "|# | " << setw(20) << "Name " << setw(7) << "| Weekday " << setw(7) << " Weekend "
		<< setw(7) << " Season |" << setw(10) << "    %    " << setw(10) << "    $    |" << right << setw(12) << "Cost $   |"
		<< "\n|**|*********************|**************************|*******************|***********|";

	//Explain purpose of program.
	introduction();
	//Create main menu to introduce other menus.
	int choice;
	char answer;
	do {
		cout << "\n\t\tMain Menu\n"
			"1. Informational Menu\n"
			"2. Purchase Menu\n"
			"3. Cancel Program\n"
			"Selection:";
		cin >> choice;
		choice = validateMenu(choice);
		switch (choice)
		{
		case 1: informationMenu(WEEKDAY, WEEKEND, SEASON,AGE_DISCOUNT,MULTI_DISCOUNT);
			break;
		case 2:
		{
			//Find out how many people are needing tickets.
			cout << "\nPlease enter how many people you are buying tickets for: ";
			cin >> size;
			while (size < 1 || cin.fail())
			{
				cout << "Invalid. Please enter how many people you are buying tickets for: ";
				cin.clear();
				cin.ignore(1000, '\n');
				cin >> size;
			}
			//Create structure array.
			info = new Customer[size];
			//For loop to populate structure and write information to output file.
			for (int count = 0; count < size; count++)
			{
				info[count].number = count + 1;
				//Run functions to gather customer information, find purchases, and calculate values then finally write to invoice.
				getCustomerInfo(info[count]);
				purchaseMenu(info[count]);
				findCost(WEEKDAY, WEEKEND, SEASON, AGE_DISCOUNT, MULTI_DISCOUNT, info[count]);
				finalCost += info[count].cost;
				writeInvoice(invoice, info[count]);
			}
		}break;
		case 3:
		{
			cout << "\nThank you for checking us out here at Green Oaks Resort! We hope to see you back soon!";
			//Close invoice file.
			invoice.close();
			//Release dynamically allocated memory array and make it a null pointer.
			delete[] info;
			info = nullptr;
			exit(0);
		}break;
		default: cout << "There has been an error, please restart program.";
		}
		if (info == nullptr)
		{
			cout << "Would you like to go back to the Main Menu? Y/N:";
			cin >> answer;
			answer = validateAnswer(answer);
		}
		else
		{
			answer = 'N';
		}
	} while (answer == 'Y');

	cout << "\nThank you for your purchases today.\nYour invoice is now available.\nGoodbye.";

	invoice << "\n====================================================================================\n"
		<< "Total Due $" << finalCost
		<< "\n====================================================================================\n"
		<< "We look forward to seeing you on our slopes!";
	//Close invoice file.
	invoice.close();
	//Release dynamically allocated memory array and make it a null pointer.
	delete[] info;
	info = nullptr;

	return 0;
}
//Function definitions.
//Function called to introduce user to the purpose of the program.
void introduction()
{
	cout << "\t\t\t\tLift Ticket Vendor\n"
		"This program will help you purchase lift tickets to the beautiful Green Oaks Mountain Ski Resort.\n"
		"Located in Arlington, Tx, the heart of the Metroplex this mountain resort was built to rival the best.\n";
}
//Function called to explain pricing and discounts.
void informationMenu(const double WEEKDAY, const double WEEKEND, const double SEASON, const double AGE, const double MULTI)
{
	char answer;
	int choice;
	do {
		cout << "\n\t\tInformation Menu\n\n"
			"1. Resort Information.\n"
			"2. Pass Price Menu.\n"
			"3. Discount Menu.\n"
			"Selection:";
		cin >> choice;
		choice = validateMenu(choice);
		switch (choice)
		{
		case 1:
		{
			cout << "\nThe resort is located at:\n"
				<< "55005 Green Oaks Mountain Drive\n"
				<< "Arlington, Tx 76006\n"
				<< "\nWith the use of snow machines our season typically runs from December through May.\n"
				<< "Our regular lift operation hours are 9am-5pm.\n"
				<< "\nOccasionally the resort will be open for night skiing so please check our website to stay informed.\n";
		}break;

		case 2:
		{
			priceMenu(WEEKDAY, WEEKEND, SEASON);
		}
		break;

		case 3:
		{
			discountMenu(AGE, MULTI);
		}
		break;

		default: cout << "\nThere has been an error, please restart program.";
			break;
		}
		cout << "\nWould you like to go back to the Information Menu again? Y/N:";
		cin >> answer;
		answer = validateAnswer(answer);
	} while (answer == 'Y');
}
//Menu to give information about prices.
void priceMenu(const double WEEKDAY, const double WEEKEND, const double SEASON)
{
	char answer;
	do {
		int choice;
		cout << "\n\t\tPrice Menu\n\n"
			<< "1. Weekday Pass Price\n"
			<< "2. Weekend Pass Price\n"
			<< "3. Season Pass Price\n"
			<< "Selection: ";
		cin >> choice;
		choice = validateMenu(choice);

		switch (choice)
		{
		case 1:
		{
			cout << "\nWeekday day passes, considered Monday through Thursday, are $" << WEEKDAY << " per day.\n";
		}break;

		case 2:
		{
			cout << "\nWeekend day passes, considered Friday through Sunday, are $" << WEEKEND << " per day.\n";
		}break;

		case 3:
		{
			cout << "\nThe season pass which gives access to the resort for the entire season is the low price of $" << SEASON << ".\n";
		}break;

		default: cout << "\nThere has been an error, please restart program.";
			break;
		}
		cout << "\nWould you like to go back to the Price Menu again? Y/N:";
		cin >> answer;
		answer = validateAnswer(answer);
	} while (answer == 'Y');
}
//Menu to give information about discounts.
void discountMenu(const double AGE, const double MULTI)
{
	char answer;
	do {
		int choice;
		
		cout << "\n\t\tDiscount Menu\n"
			"1. Age.\n"
			"2. Multi-Day.\n"
			"3. Season Pass.\n"
			"Selection:";
		cin >> choice;
		choice = validateMenu(choice);

		switch (choice)
		{
		case 1:
		{
			cout << "\nA " << static_cast<int>(AGE * 100) << "% discount will be applied for children 12 and under or seniors 65 and over.\n";
		}break;

		case 2:
		{
			cout << "\nA " << static_cast<int>(MULTI * 100) << "% discount will be applied to any purchases including multiples of 3 or more days per person.\n";
		}break;

		case 3:
		{
			cout << "\nThe Season Pass is the biggest discount you can hope for,\n it allows unlimited visits for a full season for a fraction of the cost.\n";
		}break;

		default: cout << "\nThere has been an error, please restart program.";
			break;
		}

		cout << "\nWould you like to go back to the Discount Menu again? Y/N:";
		cin >> answer;
		answer = validateAnswer(answer);
	} while (answer == 'Y');
}
//Function to get customer name and age.
void getCustomerInfo(Customer& i)
{
	//Get customer name and validate entry.
	cout << "\nPlease enter the name for customer #" << i.number << ":";
	cin.ignore();
	getline(cin, i.name);
	while (i.name.empty()||i.name==" ")
	{
		cout << "Invalid entry for name detected.\n"
		<< "\nPlease enter the name for customer #" << i.number << ":";
		cin.clear();
		getline(cin, i.name);
	}
	//Get customer age and validate entry.
	cout << "Please enter the age for " << i.name << ":";
	cin >> i.age;
	while (i.age < 1|| i.age > 100)
	{
		cout << "Invalid age entered.\n"
			<< "Please enter the age for " << i.name << ":";
		cin.clear();
		cin.ignore(1000,'\n');
		cin >> i.age;
	}
}
//Function to allow user to enter choices they wish to purchase.
void purchaseMenu(Customer& i)
{
	char answer;
	do {
		cout << "\n\t\tPurchase Menu\n\n"
			"These selections will be for " << i.name << ".\n"
			"Please make a selection for the type of pass you would like to purchase.\n";
		
		int choice;
		cout << "1. Buy Season Pass.\n"
			"2. Buy Weekday Passes.\n"
			"3. Buy Weekend Passes.\n"
			"Selection:";
		cin >> choice;
		choice = validateMenu(choice);
		switch (choice)
		{
		case 1:
		{
			i.seasonPass += 1;
			cout << "\nThat is a great choice for " << i.name << "!";
		}break;

		case 2:
		{
			int passes = 0;
			cout << "How many Weekday Passes would you like to buy for " << i.name << ": ";
			cin >> passes;
			passes = validatePasses(passes, i);
			i.weekdays += passes;
		}break;

		case 3:
		{
			int passes = 0;
			cout << "How many Weekend Passes would you like to buy for " << i.name << ": ";
			cin >> passes;
			passes = validatePasses(passes, i);
			i.weekends += passes;
		}break;

		default: cout << "There has been an error, please restart program.";
			break;
		}
		if (i.seasonPass == 0)
		{
			cout << "\nWould you like to buy more passes for " << i.name << "? Y/N: ";
			cin >> answer;
			answer = validateAnswer(answer);
		}
		if (i.seasonPass != 0)
		{
			i.weekends = 0, i.weekdays = 0, answer = 'N';
		}
	} while (answer == 'Y');
}
//Functions to validate char answers, int passes, and int menu choices.
char validateAnswer(char answer)
{
	while (!(toupper(answer) == 'Y' || toupper(answer) == 'N'))
	{
		cout << "Incorrect input. Please answer with a Y for yes or an N no: ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> answer;
	}
	answer = toupper(answer);
	return answer;
}

int validatePasses(int passes, Customer& i)
{
	while (passes < 1 || cin.fail())
	{
		cout << "Invalid entry. How many passes would you like to buy for " << i.name << ": ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> passes;
	}

	return passes;
}

int validateMenu(int choice)
{
	while (choice < 1 || choice > 3 || cin.fail())
	{
		cout << "Invalid selection!\n"
			"Valid choices are the number options 1 - 3.\n"
			"Please enter selection again: ";
		cin.clear();
		cin.ignore(1000, '\n');
		cin >> choice;
	}
	return choice;
}
//Function to calculate total days and calculate discounts then calculate cost per customer.
void findCost(const double WEEKDAY, const double WEEKEND, const double SEASON, const double AGE, const double MULTI, Customer& i)
{
	//Find total days.
	i.totalDays = i.weekdays + i.weekends;
	//Find discount percentage needed to apply.
	if (i.totalDays > 2)
	{
		i.discountPercentage += MULTI;
	}
	if (i.age < 13 || i.age > 64)
	{
		i.discountPercentage += AGE;
	}
	//Find cost of passes.
	double weekdayCost, weekendCost, seasonPassCost;
	weekdayCost = i.weekdays * WEEKDAY;
	weekendCost = i.weekends * WEEKEND;
	seasonPassCost = i.seasonPass * SEASON;
	i.cost = weekdayCost + weekendCost + seasonPassCost;
	if (i.discountPercentage != 0)
	{
		i.discount = i.cost * i.discountPercentage;
		i.cost -= i.discount;
	}
}
//Function to write information on each customer to output file.
void writeInvoice(ofstream& invoice, Customer& i)
{
	invoice << endl << left << "|" << setw(2) << i.number << "| " << setw(20) << i.name << "|    " << setw(7) << i.weekdays << "  " << setw(7) << i.weekends << "  "
		<< setw(3) << i.seasonPass << " | " << right << setw(4) << static_cast<int>(i.discountPercentage * 100) << left << setw(6) << "%" << "$" 
		<< setw(7) << showpoint << fixed << setprecision(2) << i.discount << "| $"  << setw(8) << i.cost << " |";
}
