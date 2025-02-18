#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;


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
    vector<sales_history>* history;

    //member functions
    product(string name, int ID, int stock){
        cout << setw(50) << "Entering product constructor" << endl;
        this->name = name;
        this->ID = ID;
        this->stock = stock;
        this->history = new vector<sales_history>;
        cout << setw(50) << "Exiting product constructor" << endl;
    }

    /*~product(){
        cout << setw(50) << "Entering product deconstructor" << endl;
        delete this->history;
        cout << setw(50) << "exiting product deconstructor" << endl;
    }*/
};

void addProduct(vector<product> &catalog){
    string name;
    int ID;
    int stock;
    int numHistory;

    cout << "what is the name of the product? " << endl;
    cin >> name; 
    for (int i = 0; i < catalog.size(); i ++){
        if(catalog[i].name == name){
            cout << "item name already in catalog, please retry" << endl;
            return;
        }
    }

    cout << "what is the ID number of the product? " << endl;
    cin >> ID;
    for (int i = 0; i < catalog.size(); i ++){
        if(catalog[i].ID == ID){
            cout << "item ID already in catalog, please retry" << endl;
            return;
        }
    }

    cout << "what is the stock of the product on hand? " << endl;
    cin >> stock;

    product tempProd(name, ID, stock);
    catalog.push_back(tempProd);
}


int main(){
    vector<product> catalog;

    addProduct(catalog);
    cout << catalog[0].name;
    addProduct(catalog);

    return 0;
}

