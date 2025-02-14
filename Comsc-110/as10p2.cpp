/*************************************************************************************
Decription: This program asks the user for two numbers and determines their GCF

Author: Justin Ackley
Class: COMSC-165
Date: 07/16/2024
Status: Complete
 
************************************************************************************/
#include <iostream>
using namespace std;


int gcf(int small, int big){
    int rem = big % small;

    if (rem == 0){
        return small;
    }
    else{
        return gcf(rem, small);
    }
     
    return -1;
}


int main(){
    int big, small;

    cout << "Enter the first, bigger number: ";
    cin >> big;

    cout << "\nEnter the second, smaller number: " ; 
    cin >> small;

    cout << "\nThe greatest GCF of the two is: " << gcf(small, big);
    return 0;
}