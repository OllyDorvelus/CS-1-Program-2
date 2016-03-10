// Olivier Dorvelus
// CS1300 Programming Project 2, Files and Formatting and Data Types
// due date: 2/22/16
// This program will read data from a text file, manipulate  that data and output it to another text file

// including preprocessors for file input/output, number, and string manipulation
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

// namespace
using namespace std;

// Defining the variables that will be used for the program
// Self explanatory variable names

string firstName;
string lastName;
string department;
double gross_salary;
double monthly_bonus;
double taxes;
double paycheck;
double distance_traveled;
double travelTime;
double averageSpeed;
double coffeCupsSold;
double costPerCup;
double salesAmount;

int main()
{
    ifstream inData;
    ofstream outData;
    cout << "Opening files" << endl << endl;
    // let the text files be used in this program
    inData.open("inData.txt");
    outData.open("outData.txt");

    // extracting data from inData and storing data into previously defined variables
    inData >> firstName;
    inData >> lastName;
    inData >> department;
    inData >> gross_salary;
    inData >> monthly_bonus;
    inData >> taxes;
    inData >> distance_traveled;
    inData >> travelTime;
    inData >> coffeCupsSold;
    inData >> costPerCup;
    // the actual paycheck is 70% of the gross salary
    // then apply the monthly bonus which is 105% of the gross salary after taxes
    double paycheck = (1 - (taxes / 100)) * gross_salary * (1 + (monthly_bonus) / 100);
    // speed formula is distance over time
    double averageSpeed = distance_traveled / travelTime;
    double salesAmount = coffeCupsSold * costPerCup;

    // manipulating data to output on outData.txt in desired format
    outData << "Name: " + firstName + " " + lastName + ", Department: " + department << endl;
    // next line makes every number in the program display 2 decimal points
    outData << fixed << setprecision(2);
    outData << "Monthly Gross Salary: $" << gross_salary << ',' << " Monthly Bonus: " << monthly_bonus << "%,";
    outData << " Taxes: " << taxes << '%' << endl;
    outData << "PayCheck: $" << paycheck << endl << endl;
    outData << "Distance Traveled: " << distance_traveled << " miles, ";
    outData << "Traveling Time: " << travelTime << " hours" << endl;
    outData << "Average Speed: " << averageSpeed << " miles per hour" << endl << endl;
    outData << "Number of Coffee Cups Sold: " << coffeCupsSold << ',';
    outData << " Cost: $" << costPerCup << " per cup" << endl;
    outData << "Sales Amount: $" << salesAmount;

    cout << "Data was extracted from inData.txt and output manipulated results to outData.txt" << endl << endl;

    // closes the text files
    inData.close();
    outData.close();
    cout << "Files are closed" << endl;

    // int function, must return an int data type
    return 0;
}

