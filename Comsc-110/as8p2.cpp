/*************************************************************************************
Decription: This program is an inventory managemnt system
            It will read data from either a file or from user input and then the user
            can change the data or display the data in mutliple ways. Sorry for being
            late

Author: Justin Ackley
Class: COMSC-165
Date: 07/12/2024
Status: Complete
 
************************************************************************************/

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


//structure to be used with all the inventory items
struct InventoryItem {
    string name;
    int quantity;
    double wholesale;
    double retail;
};

//vector to be used by the entire program
vector<InventoryItem> inventory;

//prototypes
void loadFile(string); //loads inventory from file
void saveInventory(string); //will save the current inventory item vector into the file
void addRecord(); //will add a new item to the inventory vector
void displayRecord(); //Displays a record of a asked for item
void changeRecord(); // changes the record of a specified item
void displayAllRecords(); // Displays records of all items
void report(); //Gives a report of total wholesale cost, retail cost, and item quantities


int main(){
    string fileName;
    string outputFile;
    char choice;

    cout << "Would you like to:\n1. Load inventory from a file\n2. Load by input" << endl;
    cin >> choice;

    if(choice == '1'){
        cout << "\n\nWhat is the name of the file you would like to load from? Please include the .txt" << endl;
        cin >> fileName;
        loadFile(fileName);
    }

    do{
        cout << "\nInventory management choices:" << endl;
        cout << "1. Add new record to file" << endl;
        cout << "2. Display a specific record" << endl;
        cout << "3. Change a specific record" << endl;
        cout << "4. Display all records" << endl;
        cout << "5. Display the inventory report" << endl;
        cout << "6. Save file and exit program" << endl;
        cout << "\nEnter choice: ";
        cin >> choice;


        switch(choice){
            case '1':
                addRecord();
                break;
            case '2': 
                displayRecord(); 
                break;
            case '3': 
                changeRecord(); 
                break;
            case '4': 
                displayAllRecords(); 
                break;
            case '5': 
                report(); 
                break;
            case '6': 
                cout << "\nWhat is the file name where you would like to store the new data?" << endl;
                cin >> outputFile;
                saveInventory(outputFile);
                break;
            default:
                cout << "Invalid choice please try again" << endl;
                break;
        }
    }while(choice!= '6');
    
    return 0;
}

//loads inventory from file
void loadFile(string fileName){
    ifstream data(fileName);
     if (!data) {
        cout << "Error opening file. Program will be starting with an empty inventory." << endl;
        return;
    }

    inventory.clear();

    //item variables
    string name;
    int quantity;
    double retail, wholesale;

    //will take in data as long as there is some to take in
    while(data >> name >> quantity >> wholesale >> retail){
        inventory.push_back({name, quantity, wholesale, retail});
    }

    data.close();

}

//will save the current inventory item vector into the file
void saveInventory(string fileName){
    ofstream file(fileName);

    if(!file){
        cout << "There was an error opening the file, please try again";
        return;
    }

    //loops through the vector and adds everything to a file
    for(InventoryItem item : inventory){
        file << item.name << " " << item.quantity << " " << item.wholesale << " " << item.retail << "\n";
    }

    file.close();

}

//will add a new item to the inventory vector
void addRecord() {
    InventoryItem newItem;
    cout << "Enter item name: ";
    cin >> newItem.name;

    cout << "Enter quantity: ";
    cin >> newItem.quantity;
    while (newItem.quantity < 0) {
        cout << "Quantity must be non-negative. Enter again: ";
        cin >> newItem.quantity;
    }

    cout << "Enter wholesale cost: ";
    cin >> newItem.wholesale;
    while (newItem.wholesale < 0) {
        cout << "Wholesale cost must be non-negative. Enter again: ";
        cin >> newItem.wholesale;
    }

    cout << "Enter retail cost: ";
    cin >> newItem.retail;
    while (newItem.retail < 0) {
        cout << "Retail cost must be non-negative. Enter again: ";
        cin >> newItem.retail;
    }

    inventory.push_back(newItem);
    cout << "Record added successfully." << endl;
}


void displayRecord(){
    string searchName;
    cout << "Enter name of Item: ";
    cin >> searchName;

    for(InventoryItem item : inventory){
        if((searchName) == (item.name)){
            cout << "\n----------------------------";
            cout << "\nItem name: " << item.name;
            cout << "\nItem quantity: " << item.quantity;
            cout << "\nItem wholesale cost: $" << item.wholesale;
            cout << "\nItem retail cost: $" << item.retail;
            cout << "\n----------------------------\n";
            return;
        }
    }
    cout << "\nItem not found, please retry or check spelling\n";
    return;



}


void changeRecord(){
    string searchName;
    cout << "Enter name of Item: ";
    cin >> searchName;


    for(InventoryItem &item : inventory){
        if((searchName) == (item.name)){
            cout << "\nEnter new item name: " << endl ;
            cin >> item.name;


            cout << "\nEnter new item quantity: " << endl;
            cin >>item.quantity;
            while (item.quantity < 0) {
                cout << "Quantity must be non-negative. Enter again: ";
                cin >> item.quantity;
            }


            cout << "\nEnter new item wholesale cost: " << endl;
            cin >> item.wholesale;
            while (item.wholesale < 0) {
                cout << "Wholesale cost must be non-negative. Enter again: ";
                cin >> item.wholesale;
            }


            cout << "\nEnter new item retail cost: " << endl;
            cin >> item.retail;
            while (item.retail < 0) {
                cout << "Retail cost must be non-negative. Enter again: ";
                cin >> item.retail;
            }
            return;

        }
        
    }
    cout << "\nItem not found, please retry or check spelling";
    return;
}


void displayAllRecords(){
    if(inventory.empty()){
        cout << "Inventory is empty, please enter values and try again";
        return;
    }

    cout << "\n----------------------------";
    for(InventoryItem item : inventory){
        cout << "\nItem name: " << item.name;
        cout << "\nItem quantity: " << item.quantity;
        cout << "\nItem wholesale cost: $" << item.wholesale;
        cout << "\nItem retail cost: $" << item.retail;
        cout << "\n----------------------------";
    }
    cout << "\n";

}


void report(){
    //cariables to total all the desired reports
    double  tWhole = 0, 
            tRetail = 0;
    int     tQuantity = 0;

    for(InventoryItem item : inventory){
        tWhole += (item.wholesale * item.quantity);
        tRetail += (item.retail * item.quantity);
        tQuantity += (item.quantity);
    }

    cout << "\n----------------------------\n" <<
            "            Report\n" <<
            "\nTotal wholesale value: $" << tWhole <<
            "\nTotal Retail value: $" << tRetail <<
            "\nTotal quanitity of items: " << tQuantity <<
            "\n----------------------------\n";
}








