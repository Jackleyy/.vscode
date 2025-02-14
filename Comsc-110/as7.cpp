/*************************************************************************
Description: This program reads names and information from a txt file and 
then lets the user sort the data and find players based on last name.

NOTE: I displayed the names as last name, first name

Author: Justin Ackley
Class: COMSC-165
Date: 07/07/2024
Status: Complete
 
*************************************************************************/





#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

const int NUM_PLAYERS = 10;

//Structure for the players
struct Player{
    string last;
    string first;
    int month;
    int day;
    int year;
};


//prototypes
void sort_data(Player[]); //sorts by last name by comparing the last names to each other using the sort function of <algortithm>
void display(Player[]); //Will display all the info of the list of players
void options(Player[]); //Displays the list of options and then passes over to another function depending on user choice
void getData(Player[]); //Gets data from a file named input.txt
void copyData(Player [], Player []); //copies data from one array to another
void findPlayer(Player []); //Will find a player based on their last name and display any matches




int main(){
    Player list[NUM_PLAYERS];
    
    //get the data
    getData(list);
    
    //display the options for the user
    options(list);



    return 0;
}




//will display the options for the user as long as they dont choose 6
void options(Player list[]){
    int opt;
    //Structure array for switch 1 to display original data
    Player copy[NUM_PLAYERS];
    copyData(list, copy);

    
    do{  
        cout << "\n\nPlease Enter a choice: ";
        cout << "\n(1 – display original data, 2 – sort data , 3 – display sorted data, 4 – search by last name, 5 – exit the program )\n";
        cin >> opt;

        switch(opt){
            //Case 1 will display the original data
            case 1:
                cout << "\nUnsorted Data: ";
                display(copy);
                break;
            case 2:
                sort_data(list);
                cout << "\n\nData has been sorted\n";
                break;
            case 3:
                sort_data(list);
                display(list);
                break;
            case 4:
                sort_data(list);
                findPlayer(list);
                break;
            case 5:
                cout << "\n\nGoodbye!";
                break;
            default: 
                cout << "\n\nInvalid choice please try again";
                break;
        }
    } while(opt != 5);
}


void findPlayer(Player list[]){
    string search; //stores the search charactars/word
    int len; //stores the length of the search query
    bool found = false; //tracks if a match has been found

    do{
        cout << "\n\n\nEnter one or more starting letters of the last name ( enter ‘//’ to quit this option):\n";
        cin >> search;
        len = search.length();
        found = false;

        //loops through the array and finds any matches
        for(int i = 0; i < NUM_PLAYERS; i++){
            //if a match is found it will declare so and display the name that matche
            if(list[i].last.substr(0, len) == search){
                cout <<"\n\nYou are searching for: " << search << " against " << list[i].last.substr(0, len);
                cout << "\nMatch found: ";
                cout << list[i].first << " ";
                cout << list[i].last << " ";
                cout << list[i].month << " ";
                cout << list[i].day << " ";
                cout << list[i].year << " ";
                found = true;
            }
            else if(search == "//"){
                break;
            }
            else if(i == 9 && !found){//If it is at the end of the array and no match has been found, error message will display
                cout << "\nNo match found";
            }
        }
        
    }while(search != "//");
}


void copyData(Player orig[], Player copy[]){
    for(int i = 0; i < NUM_PLAYERS; i++){
        copy[i].last = orig[i].last;
        copy[i].first = orig[i].first;
        copy[i].month = orig[i].month;
        copy[i].day = orig[i].day;
        copy[i].year = orig[i].year;
    }
}

//Reads data from a file called input.txt
void getData(Player players[]){
    //opens file
    ifstream input_file("input.txt");

    //checks if the file is invalid./unable to open
    if (!input_file) {
        cerr << "Failed to open input.txt\n";
        return;
    }

    //if its not then we can read the file
    for (int i = 0; i < NUM_PLAYERS; i++) {
        input_file  >> players[i].last 
                    >> players[i].first 
                    >> players[i].month
                    >> players[i].day 
                    >> players[i].year;
    }

    input_file.close();

    cout << "Data read from input.txt.\n";
}


//sorts by last name by comparing the last names to each other using the sort function of <algortithm>
void sort_data(Player players[]) {
    sort(players, players + NUM_PLAYERS, [](Player& a, Player& b) {
        return a.last < b.last;
    });
}



//Will display all the info of the list of players
void display(Player list[]){
    
    for(int i = 0; i < NUM_PLAYERS; i++){
        cout << "\n";
        cout << list[i].first << " ";
        cout << list[i].last << " ";
        cout << list[i].month << " ";
        cout << list[i].day << " ";
        cout << list[i].year << " ";
    }
}









