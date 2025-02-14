/*************************************************************************************
Decription: This program asks the user for a string and then will tell if it is 
a palindrome or not

Author: Justin Ackley
Class: COMSC-165
Date: 07/16/2024
Status: Complete
 
************************************************************************************/

#include <iostream>
#include <string>
using namespace std;




bool isPal(string str, int start, int end){

    //base case checking if it is a one letter string or a zero letter string
    if (start == end || end == -1){
        return true;
    }

    //if its not one or zero letters, we will check if the end and the beggining equal each other
    if(str[start] == str[end]){
        return(isPal(str, start + 1, end -1)); 
    }
    else{
        return false;
    }

    
    
}

int main(){
    string str;

    while(str != "stop"){
        cout << "Please provide a string you would like to check is a palindrome, type 'stop' to end the program" << endl;
        getline(cin, str);

        cout << "\nIs it a palindrome? ";

        if (isPal(str, 0, str.length()-1) == 0){
            cout << "false\n\n";
        }
        else{
            cout << "true\n\n";
        }
    }

    return 0;
}