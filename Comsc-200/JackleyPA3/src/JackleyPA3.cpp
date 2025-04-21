/*************************************************************************************
Description: This program will ask the user to enter a transaction and modify a
             pointer vector based on input.

Author: Justin Ackley
Assignment: PA2
Class: COMSC-110
Date: 09/29/2024
Status: Complete
Time spent: 2:32:00


************************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

int PRODUCT_COUNT = 0;
int ARRAY_SIZE = 50;

class sales_history{
public:
    string quarter;
    int sales;


//member functions
    sales_history(){
        cout << setw(50) << "Entering sales_history constructor" << endl;
        this->quarter = "NONE";
        this->sales = 0;
        cout << setw(50) << "exiting sales_history constructor" << endl;
    }
};

class product{
public:
    string name;
    int ID;
    int stock;
    int numHistory;
    sales_history* history;

    //member functions

    product(string name, int ID, int stock){
        cout << setw(50) << "Entering product constructor" << endl;
        this->name = name;
        this->ID = ID;
        this->stock = stock;
        history = new sales_history[10];
        cout << setw(50) << "Exiting product constructor" << endl;
    }

    ~product(){
        cout << setw(50) << "Entering product deconstructor" << endl;
        delete[] history;
        cout << setw(50) << "exiting product deconstructor" << endl;
    }
};

void addProduct(vector<product*> &catalog){
    string name;
    int ID;
    int stock;
    int numHistory;

    cout << "what is the name of the product? " << endl;
    cin >> name;
    for (int i = 0; i < catalog.size() ; i ++){
        if(catalog[i]->name == name){
            cout << "item name already in catalog, please retry" << endl;
            return;
        }
    }

    cout << "what is the ID number of the product? " << endl;
    cin >> ID;
    for (int i = 0; i < catalog.size(); i ++){
        if(catalog[i]->ID == ID){
            cout << "item ID already in catalog, please retry" << endl;
            return;
        }
    }

    cout << "what is the stock of the product on hand? " << endl;
    cin >> stock;

    product*tempProd = new product(name, ID, stock);
    catalog.push_back(tempProd);
    cout << "Product ID #" << ID << " has been added" << endl;

}

void deleteProduct(int ID, vector<product*> &catalog){
    for (int i = 0; i < catalog.size() ; i++){
        if(catalog[i]->ID == ID){
            delete catalog[i];
            catalog.erase(catalog.begin() + i);
            cout << "Product ID #" << ID << " has been deleted" << endl;
            return;
        }
    }
    cout << "Product ID #" << ID << " has not been found in Array" << endl;
}

void listCatalog(vector<product*> &catalog){
    for (int i = 0; i < catalog.size() ; i++){
        cout << setw(15) << "Product " << i + 1 << endl;
        cout << "Product " << i + 1<< " name: " << catalog[i]->name << endl;
        cout << "Product " << i  + 1<< " ID #: " << catalog[i]->ID << endl;
        cout << "Product " << i +1 << "stock: " << catalog[i]->stock << endl;
        cout << "\n";
    }
    cout << "Total amount of products: " << catalog.size() << endl << "\n";
}


int main(){
    vector<product*> catalog;
    char choice;

    while(tolower(choice) != 'x'){
        cout << setw(15) << "\nTransaction List: " << endl;
        cout << "'A': Will add a new product to the catalog" << endl;
        cout << "'D': Will delete a product from the catalog" << endl;
        cout << "'L': Will list all the current products in the catalog" << endl;
        cout << "'X': Will exit the program" << endl;

        cout << "Transaction choice: ";
        cin >> choice;
        choice = tolower(choice);
        cout << endl;

        switch(choice){
            case 'a':
                addProduct(catalog);
                break;
            case 'd': {
                int deletionID = 0;
                cout << "ID of product to delete: ";
                cin >> deletionID;
                deleteProduct(deletionID, catalog);
                break;
            }
            case 'l':
                listCatalog(catalog);
                break;
            case 'x':
                cout << "Goodbye!";
                break;
            default:
                cout << "invalid choice, please retry" << endl;
        }
    }


    //dealocate remaining vector memory

    for (int i = 0; i < catalog.size(); i++) {
        delete catalog[i];
    }


    return 0;
}

