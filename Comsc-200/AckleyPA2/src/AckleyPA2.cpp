/*************************************************************************************
Description: This program will read data from a char data file and then display the
             information

Author: Justin Ackley
Assignment: PA2
Class: COMSC-110
Date: 09/15/2024
Status: Complete


************************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <fstream>
using namespace std;

static int ARRAY_SIZE = 100;


struct Instructor{
    int salary;
    int idNum;

    char midIn;

    string payCode;
    string firstName;
    string lastName;
    string depCode;

};


// Function prototypes

// Reads data input from a char array and populates the various parts of an Instructor object
void input_data(Instructor &teach, char data[]);

// Generates a report from an array of Instructor pointers
void report(Instructor* iArray[]);

// Calculates the average salary and determines the highest salary
int salary(Instructor* iArray[], Instructor* &maxSal);



int main(){

	ifstream infile;
	infile.open("pa2data");


	if(!infile.is_open()){
	        cout << "Error opening the file, please troublshoot and retry";
	        return 1;
	    }

    Instructor* iArray[ARRAY_SIZE] = {nullptr};
    char data[46]; //4600 assummes there will be no more than 100 entries
    char x;//to store chars temporarily

    int array_count = 0; //tracks which elemtn of the array to put a new struct in
    while(infile.peek()!=EOF){
        for(int i =0; i < 46; i++){ //reads file char by char and puts it in data
            infile.get(x);
            data[i] = x;
            if(i%45 == 0 && i!= 0){ //creates a new instructor object every 46 characters
                iArray[array_count] = new Instructor;
                input_data(*(iArray[array_count]), data);
                array_count++;
            }


        }
    }

    //displays the report
    report(iArray);

    //displays average and highest salary
    Instructor* maxSal;

    cout << setfill('=') << setw(83);
    cout << "\n" << "Average Salary: " << salary(iArray, maxSal);
    cout << "\nHighest Salary: " ;
    cout << maxSal->firstName << maxSal->lastName;
    cout << "\n" << setfill('=') << setw(83) << "\n";


    //dump the memory and close file
    for (int i = 0; i < ARRAY_SIZE; i++){
        delete(iArray[i]);
    }

    infile.close();

    return 0;
}

//reads data input from "data" and inputs it into the
//various parts of an instrucotr object
void input_data(Instructor &teach, char data[]){
    teach.idNum = stoi(string(data, 6));
    teach.payCode = string(data + 6, 3);
    teach.firstName = string(data + 9, 10);
    teach.midIn = data[19];
    teach.lastName = string(data + 20, 15);
    teach.salary = stoi(string(data + 35, 6));
    teach.depCode = string(data + 41, 5);

}

void report(Instructor* iArray[]){
    //making the header
    cout << "Employee ID";
    cout << setw(12) << "Last name"  ;
    cout << setw(17) << "MI";
    cout << setw(13) << "First Name";
    cout << setw(17) << "Department";
    cout << setw(11) << "Salary" << endl;
    cout << setfill('=') << setw(83) << "\n";


    for (int i = 0; iArray[i] != nullptr; i++){
        cout << setfill(' ') << setw(1)<< (*iArray[i]).idNum << (*iArray[i]).payCode;
        cout << setw(23) << (*iArray[i]).lastName;
        cout << setw(7) << (*iArray[i]).midIn;
        cout << setw(14) << (*iArray[i]).firstName;
        cout << setw(15) << (*iArray[i]).depCode;
        cout << setw(13) << (*iArray[i]).salary;
        cout << "\n";
    }

}

int salary(Instructor* iArray[], Instructor* &maxSal){
    int highSal = 0;
    int total = 0, count = 0;

    for (int i = 0; iArray[i] != nullptr; i++){
        total += iArray[i]->salary;
        count = i ;

        //checks if the next salary is higher
        if(iArray[i]->salary > highSal){
            highSal = iArray[i]->salary;
            maxSal = iArray[i];
        }
        //adds up the salaries

    }
    return total/count;
}

