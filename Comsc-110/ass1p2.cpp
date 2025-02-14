/*************************************************************************************
Decription: This program asks a user how many tellers a bank has and then asks
how many sick days they had over a course of three years. After it has the info
it will then display it

Author: Justin Ackley
Class: COMSC-165
Date: 06/11/2024
Status: Complete
 
************************************************************************************/

#include <iostream>
using namespace std;

int main(){
    //intializing variables
    int totalTellers;
    int sickDays = 0;
    int temp;


    //Inputs the amount of tellers for the loop to work
    cout << "How many tellers worked at Nation’s Bank during each of the last three years? ";
    cin >> totalTellers;
    cout << "\n\n";

    //Depending on how many tellers there are it will loop through that many times, asking how many sick days each had for three years
    for (int i = 1; i <= totalTellers; i++){
        for (int j = 1; j<=3; j++){
            cout << "How many days was teller " << i << " out sick during year " << j <<  "?\n";
            cin >> temp;

            //totaling the total sick days
            sickDays += temp;

        }
        cout << "\n";
    }
    cout << "\nThe " << totalTellers << " tellers were sick a total of " << sickDays << " during the last three years";
    
    return 0;
}