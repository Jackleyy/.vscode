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


    bool operator ==(product &prod){
        if(stock == prod.stock){
            return true;

        }
        else{
            return false;
        }
    }

    bool operator >(product &prod){
        if (stock > prod.stock){
            
            return true;
        }
        else{
            return false;
        }
    }


    product(product &prod, int ID2){
        cout << setw(50) << "Entering product copy constructor" << endl;
        this->name = prod.name;
        this->ID = ID2;
        this->stock = prod.stock;
        history = new sales_history[10];
        cout << setw(50) << "Exiting product copy constructor" << endl;
    }

    ~product(){
        cout << setw(50) << "Entering product deconstructor" << endl;
        delete[] history;
        cout << setw(50) << "exiting product deconstructor" << endl;
    }
};


//prototypes
void addProduct(vector<product*> &catalog);
void addSH(vector<product*> &catalog);



void addSH(vector<product*> &catalog){
    int ID;
    int index;
    cout << "what is the product ID of the product you would like to add a sales History to?" <<endl;
    cin >> ID;

    for (int i = 0; i < catalog.size(); i ++){
        if(catalog[i]->ID == ID){
            index = i;
            continue;
        }
        else if(i == catalog.size() -1){
            cout << "Product ID not found" << endl;
            return;
        }
    }

    char ans;
        for (int i = 0; i < 10; i++){
            cout << "would you like to enter a history for sales history object #" << i+1 << " ? (y/n)" << endl;
            cin >> ans;
            
            if(ans == 'n'){
                return;
            }

            cout << "please enter the quarter for sales history object #" << i+1 << endl;
            cin >> catalog[index]->history[i].quarter;

            cout << "please enter the number sold for sales history object #" << i+1 << endl;
            cin >> catalog[index]->history[i].sales;
        }
        

    }

    void copy(vector<product*> &catalog){
        int ID1;
        int index;
        cout << "what is the product ID of the product you would like to copy?" <<endl;
        cin >>ID1;

        for (int i = 0; i < catalog.size(); i ++){
            if(catalog[i]->ID == ID1){
                index = i;
                break;
            }
            else if (i == catalog.size()){
                cout << "Product ID not found" << endl;
                return;
            }
        }

        int ID2;
        cout << "Please enter a new ID for the copied product" << endl;
        cin >> ID2;

        //making new product Prod with the dereferenced address of oru given prodyct
        product*Prod = new product(*(catalog[index]), ID2);
        catalog.push_back(Prod);
        cout << "Product ID #" << ID2 << " has been added" << endl;
    }

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
        cout << "Product " << i +1 << " stock: " << catalog[i]->stock << endl;

        if (catalog[i]->history[i].quarter == "NONE"){
            cout << setw(7.5) << "No sales history present" << endl;
            cout << "\n";
            continue;
        }

        cout << setw(5) << "Product " << i + 1 << " history" << endl;
        cout << setw(7.5) << "Quarter: " << catalog[i]->history[i].quarter << endl;
        cout << setw(7.5) << "Amount sold: " << catalog[i]->history[i].sales << endl;
        cout << "\n";
    }
    cout << "Total amount of products: " << catalog.size() << endl << "\n";
}

void compare(vector<product*> &catalog){
    int ID1, ID2, index1, index2;

    cout << "Enter the first ID to compare" << endl;
    cin >> ID1;

    cout << "Enter the second ID to compare" << endl;
    cin >> ID2;

    for (int i = 0; i < catalog.size(); i ++){
            if(catalog[i]->ID == ID1){
                index1 = i;
                break;
            }
            else if (i == catalog.size()){
                cout << "Product ID 1 not found" << endl;
                return;
            }
        }
    
    for (int i = 0; i < catalog.size(); i ++){
            if(catalog[i]->ID == ID2){
                index2 = i;
                break;
            }
            else if (i == catalog.size()){
                cout << "Product ID 2 not found" << endl;
                return;
            }
        }
    if(*catalog[index1] == *catalog[index2]){
        cout << "Product ID# " << ID1 << " and Product ID# " << ID2 << " are of equal quantity" << endl;
    }
    else if(*catalog[index1] > *catalog[index2]){
        cout << "Product ID# " << ID1 <<  " has a greater quantity" << endl;
    }
    else{
        cout << "Product ID# " << ID2 <<  " has a greater quantity" << endl;
    }
    
    }


int main(){
    vector<product*> catalog;
    char choice;

    while(tolower(choice) != 'x'){
        cout << setw(15) << "\nTransaction List: " << endl;
        cout << "'A': Will add a new product to the catalog" << endl;
        cout << "'D': Will delete a product from the catalog" << endl;
        cout << "'L': Will list all the current products in the catalog" << endl;
        cout << "'S': Will add a sales history for a given product ID" << endl;
        cout << "'C': Will copy an existing product with a new history" << endl;
        cout << "'O': Will compare prodcucts based on ID" << endl;

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
            case 's':
                if (catalog.size() == 0){
                    cout << "no products to modify" << endl;
                    break;
                }
                else{
                    addSH(catalog);
                }
                break;
            case 'c':
                if (catalog.size() == 0){
                    cout << "no products to copy" << endl;
                    break;
                }
                else{
                    copy(catalog);
                }
                break;
            case 'o':
                if (catalog.size() == 0){
                    cout << "no products to compare" << endl;
                    break;
                }
                else{
                    compare(catalog);
                }
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

