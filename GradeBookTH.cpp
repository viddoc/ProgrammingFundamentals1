//This is a program to calculate grades and output a report.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;
//Function prototypes
void introduction();
void validateGrade(float, int, string);
void getLabGrades(float[], int, string);
void getQuizGrades(float[], int, string);
void getExamGrades(float[], int, string);
float getLowestGrade(float [], int);
float getTotalGrade(float[], int);
char getLetterGrade(double);
void reportLine(float[],float[],float[]);
int main()
{
    //Constant Variables
	const int LAB = 6, QUIZ = 10, EXAM = 2;
	const double LWEIGHT = .35, QWEIGHT = .35, EWEIGHT = .30;
	//Arrays
	float lab[LAB], quiz[QUIZ], exam[EXAM];
	string gradeType[] = { "Lab", "Quiz" ,"Exam" };
	//Variables
	float lowestLab, lowestQuiz, totalLab=0, totalQuiz=0, totalExam=0, averageLab, averageQuiz, averageExam;
	double weightLab, weightQuiz, weightExam, finalGrade;
	char answer, letterGrade;
	//Do-While loop to allow program to be run as many times as wanted.
	do {
		//Call introduction.
		introduction();
		//Call functions to get grades and then find the lowest and the total.
		getLabGrades(lab, LAB, gradeType[0]);
		lowestLab = getLowestGrade(lab , LAB);
		getQuizGrades(quiz, QUIZ, gradeType[1]);
		lowestQuiz = getLowestGrade(quiz, QUIZ);
		getExamGrades(exam, EXAM, gradeType[2]);
		totalLab = getTotalGrade(lab, LAB);
		totalQuiz = getTotalGrade(quiz, QUIZ);
		totalExam = getTotalGrade(exam, EXAM);
		//Calculate the averages and the weight of each.
		averageLab = (totalLab - lowestLab) / (LAB-1);
		averageQuiz = (totalQuiz - lowestQuiz) / (QUIZ-1);
		averageExam = totalExam / EXAM;
		weightLab = averageLab * LWEIGHT;
		weightQuiz = averageQuiz * QWEIGHT;
		weightExam = averageExam * EWEIGHT;
		//Calculate final grade and grade letter.
		finalGrade = weightLab + weightQuiz + weightExam;
		letterGrade = getLetterGrade(finalGrade);
		//Create report file.
		ofstream report;
		report.open("GradeReport.txt");
		//Validate file opened.
		if (!report)
		{
			cout << "Error!\nPlease restart program.";
			exit(0);
		}
		//Writing all values to report.
		report << setprecision(2) << fixed << showpoint;
		report << "\t\t\tGrade Report\n\n";
		report << "\t\t\tLabs\tQuizzes\tExams\n";
		for (int count = 0; count < QUIZ; count++)
		{
			if (count < EXAM)
			{
				report << count + 1 << "\t\t\t" << lab[count] << "\t" << quiz[count] << "\t" << exam[count] << endl;
			}
			else if (count < LAB)
			{
				report << count + 1 << "\t\t\t" << lab[count] << "\t" << quiz[count] << endl;
			}
			else
			{
				report << count + 1 << "\t\t\t\t" << quiz[count] << endl;
			}
		}
		report << "-------------------------------------------------\n";
		report << "Lowest:\t\t\t" << lowestLab << "\t" << lowestQuiz << endl;
		report << "Average:\t\t" << averageLab << "\t" << averageLab << "\t" << averageExam << endl;
		report << "Percentage:\t\t" << LWEIGHT << "\t" << QWEIGHT << "\t" << EWEIGHT << endl;
		report << "Wt.Total\t\t" << weightLab << "\t" << weightQuiz << "\t" << weightExam << endl;
		report << "Final Grade:\t\t" << finalGrade << "\t" << letterGrade;
		//Close report file.
		report.close();
		//Prompt for running program again
		cout << "\nWould you like to run program again (Y/N)?";
		cin >> answer;
		while (!(answer == 'Y' ||  answer == 'N' ))
		{
			cout << "Error";
			cout << "\nWould you like to run program again (Y/N)?";
			cin >> answer;
		}
	} while (answer == 'Y' || answer == 'y');
	return 0;
}
//Function to introduce user to the purpose of the program.
void introduction()
{
	cout << "\t\t\t\t******Gradebook Calculator******\n";
	cout << "\t\t********************************************************************";
	cout << "\n\t\tThis program is designed to help with creating a gradebook report.\n";
	cout << "\t\tIt will require you to enter 6 Lab grades, 10 Quiz grades, and 2 Exam grades.\n";
	cout << "\t\tThe lowest Lab grade and lowest Quiz grade will be dropped.\n";
	cout << "\t\tThis program will then calculate the average for the Labs, Quizzes, and Exams.\n";
	cout << "\t\tIt will also calculate the weight total for each category and the final letter grade.\n";
	cout << "\t\tThe program will output a report from this data named GradeReport.txt.\n";
	cout << "\t\t********************************************************************";
}
//Function to retrieve Lab grades. 
void getLabGrades(float labGrades[], int size, string gradeType)
{
	float grade = 0;
	cout << "\n\nPlease enter the " << gradeType << " grades now. Enter one " << gradeType << " at a time then press enter. The max grade for any " << gradeType << " is 100:" << "\n\n";
	for (int count = 0; count < size; count++)
	{
		cout << "Please enter grade for " << gradeType << "#" << count + 1 << ": ";
		cin >> grade;
		while (grade < 0 || grade>100)
		{
			cout << "The grade entered is invalid.\n";
			cout << "Please enter grade for " << gradeType << "#" << count + 1 << ": ";
			cin >> grade;
		}
		labGrades[count] = grade;
	}
}
//Function to retrieve Quiz grades.
void getQuizGrades(float quizGrades[], int size, string gradeType)
{
	float grade = 0;
	cout << "\n\nPlease enter the " << gradeType << " grades now. Enter one " << gradeType << " at a time then press enter. The max grade for any " << gradeType << " is 100:" << "\n\n";
	for (int count = 0; count < size; count++)
	{
		cout << "Please enter grade for " << gradeType << "#" << count + 1 << ": ";
		cin >> grade;
		validateGrade(grade, count, gradeType);
		quizGrades[count] = grade;
	}
}
//Function to retrieve Exam grades.
void getExamGrades(float examGrades[], int size, string gradeType)
{
	float grade = 0;
	cout << "\n\nPlease enter the " << gradeType << " grades now. Enter one " << gradeType << " at a time then press enter. The max grade for any " << gradeType << " is 100:" << "\n\n";
	for (int count = 0; count < size; count++)
	{
		cout << "Please enter grade for " << gradeType << "#" << count + 1 << ": ";
		cin >> grade;
		validateGrade(grade, count, gradeType);
		examGrades[count] = grade;
	}
}
//Function to validate grade input.
void validateGrade(float grade, int count, string gradeType)
{
	while (grade < 0 || grade>100)
	{
		cout << "The grade entered is invalid.\n";
		cout << "Please enter grade for " << gradeType << "#" << count + 1 << ": ";
		cin >> grade;
	}
}
//Function to find lowest grade.
float getLowestGrade(float grades[], int size)
	{
		float lowestGrade;
		lowestGrade = grades[0];
		for (int count = 1; count < size; count++)
		{
			if (grades[count] < lowestGrade)
				lowestGrade = grades[count];
		}
		return lowestGrade;
	}
//Function to find total grade.
float getTotalGrade(float grades[], int size)
{
	float totalGrade = 0;
	for (int count = 0; count < size; count++)
	{
		totalGrade += grades[count];
	}
	return totalGrade;
}
//Function to find letter grade.
char getLetterGrade(double finalGrade) 
{
	char letter;
	if (finalGrade >= 90)
		letter = 'A';
	else if (finalGrade >= 80)
		letter = 'B';
	else if (finalGrade >= 70)
		letter = 'C';
	else if (finalGrade >= 60)
		letter = 'D';
	else
		letter = 'F';
	return letter;
}