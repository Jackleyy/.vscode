/*************************************************************************************
Decription: This program totals tyhe number of votes for a certain drink and
displays the information after a sentimal value is provided

Author: Justin Ackley
Class: COMSC-165
Date: 06/11/2024
Status: Complete
 
************************************************************************************/

#include <iostream>
using namespace std;

int main(){
    //initiailizing variables
    int coffee = 0;
    int tea = 0;
    int coke = 0;
    int juice = 0;
    int userCount = 0;
    int input; 
    
    
    //Lists the choices
        cout << "Please input votes for the following choices: \n1 for coffee\n2 for tea\n3 for coke\n4 for juice\n\nIf you would like to end the voting process enter '-1'";
        
    //Will ask the user their choice and receive a vote until program is terminated by sentinal value
    while(input != -1){
        cout << "\nPlease input the favorite beverage of person #" << userCount +1<< " ";
        cin >> input;
        cout << "\n";
        
        //adds the vote to the corresponding choice
        switch (input){
            case 1:
                coffee += 1;
                userCount +=1;
                break;
            case 2:
                tea += 1;
                userCount +=1;
                break;
            case 3:
                coke += 1;
                userCount +=1;
                break;
            case 4:
                juice += 1;
                userCount +=1;
                break;
            case -1:
                break;
            default:
                cout << "\ninvalid choice, try again\n";
        }
    }
    
    //displaying final info
    cout << "\n\nThe total number of people surveyed is " << userCount << ". The results are as follows:";
    
    cout << "\n\nBeverage Number Votes \n***********************";
    cout << "\nCoffee: " << coffee;
    cout << "\nTea: " << tea;
    cout << "\nCoke: " << coke;
    cout << "\nOrange juice: " << juice;
    
    
    
    
    
    return 0;
}