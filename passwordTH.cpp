//Tommy Hudson program to test a password against specified criteria.
#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;

int main()
{
	//Variables
	const int PASSWORD_SIZE = 50;
	char password[PASSWORD_SIZE];
	int uppercase=0, lowercase=0, digit=0;
	//Explain scope of program.
	cout << "\t\t\t\tPassword Verification Program\n\n";
	cout << "\tThis program will verify your password to insure it meets the following criteria:\n";
	
	//do-while Loop to verify conditions met.
	do
	{
		//
		uppercase = 0, lowercase = 0, digit = 0;
		//Explain criteria neccessary to succeed.
		cout << "\nThe password should be at least 10 characters long.\n";
		cout << "The password should contain at least one uppercase and at least one lowercase letter.\n";
		cout << "The password should have at least one digit.\n\n";

		cout << "Please enter your password: ";
		//Get password from user.
		cin.getline(password, PASSWORD_SIZE);
		//Test password against criteria listed.
		for (int count = 0; count < strlen(password); count++)
		{
			if (isupper(password[count]))
			{
				uppercase++;
			}
			if (islower(password[count]))
			{
				lowercase++;
			}
			if (isdigit(password[count]))
			{
				digit++;
			}
		}
		//Explanation for why password may have failed.
		if (strlen(password) < 10)
		{
			cout << "\nThe password does not contain at least 10 characters.";
		}
		if (uppercase == 0)
		{
			cout << "\nThe password does not contain at least one uppercase letter.";
		}
		if (lowercase == 0)
		{
			cout << "\nThe password does not contain at least one lowercase letter.";
		}
		if (digit == 0)
		{
			cout << "\nThe password does not have at least one digit.";
		}
		if (uppercase == 0 || lowercase == 0 || digit == 0 || strlen(password) < 10)
		{
			cout << "\n\nPlease try again.\n";
		}
		
	} while (uppercase == 0 || lowercase == 0 || digit == 0 || strlen(password) < 10);
		
	//Congratulate on success.
	cout << "\nPassword successful!";

	return 0;
}