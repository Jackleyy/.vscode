/*************************************************************************************
Decription: This program will ask the user for how many elements they want to store
            and then dynamically allocate an array for that many elements.
            The user can then modify the array with various elements

Author: Justin Ackley
Class: COMSC-165
Date: 07/18/2024
Status: Complete
 
************************************************************************************/

#include <iostream>
#include <string>
using namespace std;


class Library{
    double * shelf;
    int LENGTH;

    public:
        //constructor
        Library(int length){
            LENGTH = length -1;
            shelf = new double[length];
            for(int i = 0; i < LENGTH; i++){
                shelf[i] = 0;
            }
        }

        void add(int index, double num){
            shelf[index] = num;
        }

        double get(int index){
            return shelf[index];
        }

        double getHigh(){
            int high = shelf[0];
            for(int i = 0; i < LENGTH; i++){
                if (shelf[i] > high){
                    high = shelf[i];
                }
            }
            return high;
        }

        double getLow(){
            int low = shelf[0];
            for(int i = 0; i < LENGTH; i++){
                if (shelf[i] < low){
                    low = shelf[i];
                }
            }
            return low;
        }

        double average(){
            double total = 0;
            double ave = 0;
            int index = 0;

            for(int i = 0; i < LENGTH; i++){
                total += shelf[i];
                if(shelf[i] != 0){
                    index++;
                }
            }
            ave = total/index;
            return ave;
        }

        void print(){
            cout << "Current array: {";
            for(int i = 0; i < LENGTH; i++){
                cout << shelf[i] << ", ";
            }
            cout << " }";
        }

        void END(){
            delete shelf;
        }

};

int main(){

    int length;
    int choice;


    cout << "How many elements would you like to store? ";
    cin >> length;

    Library lib(length);

    while (choice != 7){
        choice = 0;
        double num = 0;
        int index = 0;

        cout << "\nWhat would you like to do?\n"
                 << "1. Store a number at a given index\n"
                 << "2. Retrieve a number from a given index\n"
                 << "3. Find the highest value in the array\n"
                 << "4. Find the lowest value in the array\n"
                 << "5. Find the average of the array\n"
                 << "6. Print the current array\n"
                 << "7. End the program\n"
                 << "Enter choice: ";
        cin >> choice;

        switch(choice){ 
            case 1 :
                cout << "What number would you like to add? " << endl;
                cin >> num;

                cout << "Where would you like to add it? " << endl;
                cin >> index;

                lib.add(index, num);
                
                cout << "Number added!" << endl;
                break;

            case 2: 
                cout << "What index would you like to check? ";
                cin >> index;
                cout << "The number at index " << index << " is " << lib.get(index) << endl;
                break;

            case 3:
                cout << "The highest value in the array is: " << lib.getHigh() << endl;
                break;
            case 4:
                cout << "The lowest value in the array is: " << lib.getLow() << endl;
                break;
            case 5: 
                cout << "The average of the array is: " << lib.average() << endl;
                break;
            case 6:
                lib.print();
                break;
            case 7:
                cout << "Goodbye!";
                lib.END();
                break;
            default:
                cout << "Invalid choice, please enter a new input {1-6}";
                break;
        }
    }

    return 0;
}