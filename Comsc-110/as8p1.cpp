/*************************************************************************************
Decription: This program will either encrpyt or decrypt using a 1 space right shift
            ceaser cypher

Author: Justin Ackley
Class: COMSC-165
Date: 07/12/2024
Status: Complete
 
************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char shiftChar(char, int);
void processFile(string, string, int);

int main(){
    //intiliaze the file nanes
    string inFile, outFile;
    int choice;

    cout << "Would you like to:\n1: Encrypt a file\n2: Decrypt a file\n";
    cin >> choice;

    cout << "What is the name of the input file? Please include the .txt\n";
    cin >> inFile;

    cout << "What is the name of the output file? Please include the .txt\n";
    cin >> outFile;


    if(choice == 1){
        processFile(inFile, outFile, 1);
        cout << "Encryption complete" << endl;

        ifstream toConsole(outFile);

        if(toConsole){
            cout << "\nEncrypted contents:\n";
            string line;
            while(getline(toConsole, line)){
                cout << line << endl;
            }
            toConsole.close();
        }
    }
    else if(choice == 2){
        processFile(inFile, outFile, -1);
        cout << "Decryption complete." << endl;

        ifstream toConsole(outFile);

        if(toConsole){
            cout << "\nDecrytpted contents:\n";
            string line;
            while(getline(toConsole, line)){
                cout << line << endl;
            }
            toConsole.close();
        }
        else{
            cout << "Error opening output file" << endl;
        }
    }
    else{
        cout << "Invalid choice, restart program";
    }

    return 0;
}

//shifts the char one to the left to encrypt it
char shiftChar(char ch, int shift){
    if(isalpha(ch)){//checking if its even a letter
        char base;
        //if it is a letter then we check if its uppercase
        //we then set it to the corresponding A to know its position (65 or 97)
        if (isupper(ch)){
            base = 'A';
        }
        else{
            base = 'a';
        }
        return(ch - base + shift + 26) %26 + base;
        /*
        ch-base sets it to 0-25
        then +shift add the shift amount to code it
        adding 26 makes it so there are no negative values (shift <=26)
        %26 handles wrap around if it goes above 26
        finally +base will convert it back to the correct ASCII 
        */
    }
    return ch;
}


void processFile(string inputFile, string outputFile, int shift){
    //openign both input and output fikes
    ifstream inFile(inputFile);
    ofstream outfile(outputFile);

    if(!inFile || !outfile){
        cout << "There was a problem opening the file, please retry" << endl;
        return;
    }

    char ch;

    //translates each character and then puts it back in place
    while (inFile.get(ch)){
        outfile.put(shiftChar(ch, shift));
    }

    //closing the files
    inFile.close();
    outfile.close();


}