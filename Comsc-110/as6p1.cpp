/*************************************************************************************
Decription: This program will first ask a user for a string and then provide several
            options of edditing the string

Author: Justin Ackley
Class: COMSC-165
Date: 06/30/2024
Status: Complete
 
************************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

#define max_len 256

char* getString(char[]);
void options(char*);
int search(char *, char *);
void inserter(char[], char[]);
void append(char *);
void strDel(char *);
void replace(char *, char *, char *);


int main(){
    char mainStr[max_len];
    char choice;


    getString(mainStr);

    do{
        options(mainStr);
        cin >> choice;

        switch(choice){
            case 's':{
                char target[max_len];
                cout << "\nEnter a string to find the index of:\n";
                cin.ignore();
                cin.getline(target, max_len);

                if(search(mainStr, target)){
                    cout << "\nThe index of the string is: " << search(mainStr, target) -1; //subtracts one to find the right index
                }
                else{
                 cout << "\nString not found";
                }

                break;
            }

            case 'i':{
                char insertee[max_len];

                cout << "\nWhat would you like to store? ";
                cin.ignore();
                cin.getline(insertee, max_len);

                inserter(mainStr, insertee);
                break;
            }

            case 'a':{
                append(mainStr);
                break;
            }

            case 'd':{
                strDel(mainStr);
                break;
            }

            case 'r':{
                char oldStr[max_len], newStr[max_len];
                cout << "\nEnter the string to be replaced:\n";
                cin.ignore(); 
                cin.getline(oldStr, max_len);

                cout << "\nEnter the replacing string:\n";
                cin.getline(newStr, max_len);

                replace(mainStr, oldStr, newStr);
                break;
            }

            case 'e':{
                cout << "\nBye";
                break;
            }

            default: {
                cout << "\nInvalid option, please retry";
                break;
            }
        }

        
    }while(choice != 'e');

    return 0;
}


void replace(char *str, char *oldStr, char *newStr) {
    int len = strlen(str);
    int oldLen = strlen(oldStr);
    int newLen = strlen(newStr);

    if (oldLen == 0) {
        // If oldStr is empty, just appends newStr to str
        strcat(str, newStr);
        return;
    }

    // Allocate temporary buffer to hold the modified string
    char temp[max_len];
    temp[0] = '\0'; // Initialize it to empty string

    // Initialize variables for iterating through str
    char *ptr = str;
    char *next;

    while ((next = strstr(ptr, oldStr)) != NULL) {
        strncat(temp, ptr, next - ptr);

        // Append newStr to temp
        strcat(temp, newStr);

        ptr = next + oldLen;
    }

    // Append remaining characters in str to temp
    strcat(temp, ptr);

    // Copy temp back to str
    strcpy(str, temp);
}




void options(char* mainStr){
    cout << "\n\nCurrent string: " << mainStr;

    cout << "\nPlease select an option:\n ";
    cout << "(s – search, i - insert, a – append, d – delete, r – replace, e – exit)" << endl;
}
char* getString(char str[]){
    cout << "Please enter a string to be stored:\n";
    cin.getline(str, max_len);
    return str;
}

int search(char *str, char *target){
    char *arrow = strstr(str, target); 
    int position;
    if(arrow){
        position = arrow - str;
        return position + 1; //if it is found, it will return a position plus 1 to ensure it is not consider 0 (false)
    }
    else{
        return 0; //if its not found
    }
}

void inserter(char str[], char insert[]){
    int length = strlen(str);
    int insLen = strlen(insert);
    int index;

    cout << "\nWhere would you like to insert the new string? ";
    cin >> index;

    while(index < 0 || index > length){
        cout << "\nInvalid index please try again";
        cout << "\nWhere would you like to insert the new string? ";
        cin >> index;
    }

    memmove(str + index + length, str + index, length - index + 1);
    memcpy(str + index, insert, length);
    strcat(str, " day");
}

//adds something to the end
void append(char *str){
    char add[max_len];

    cout << "what would you like to add the the end of the string?\n";
    cin.ignore(); 
    cin.getline(add, max_len);

    strcat(str, add);
}

void strDel(char *str){
    char remove[max_len];
    
    cout << "\nWhat would you like to remove?\n";
    cin.ignore();
    cin.getline(remove, max_len);


    char *arrow = strstr(str, remove);

    if(arrow){
        memmove(arrow, arrow + strlen(remove), strlen(arrow + strlen(remove)) + 1);
    }
}

