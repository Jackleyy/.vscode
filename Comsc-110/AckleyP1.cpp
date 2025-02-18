/*************************************************************************************
Description:

Author: Justin Ackley
Assignment: PA1
Class: COMSC-110
Date: 09/8/2024
Status: Complete


************************************************************************************/

#include <iostream>
#include <cstdlib>
using namespace std;

//function prototypes
void allocateArray(int, int*&);
void fillArray(int, int*&);
void displayArray(int, int*&);
void sortArray(int, int*&);
int checkDupe(int, int*&);
void mergeArrays(int , int* &, int* &, int* &);
void deleteArray(int * &);


int main() {
    srand(time(0));
    
    static int b4SIZE = 50; //size for array before (b4) merge
    static int mergeSIZE = 100; //size for merged arrays

    //establishing array 1
	int * add1 = nullptr;
	allocateArray(b4SIZE, add1);
    fillArray(b4SIZE, add1);
    
    
    //establishing array 2
    int *add2 = nullptr;
    allocateArray(b4SIZE, add2);
    fillArray(b4SIZE, add2);


    //establishing the merging third merging array
    int *dest = nullptr;
    allocateArray(mergeSIZE, dest);


    //display unsorted arrays 
    cout << "Array 1: ";
    displayArray(b4SIZE, add1);

    cout << "\n\nArray 2: ";
    displayArray(b4SIZE, add2);

    //sort the arrays and display 
    sortArray(b4SIZE, add1);
    cout << "\n\nSorted Array 1: ";
    displayArray(b4SIZE, add1);
    cout << "\n";

    sortArray(b4SIZE, add2);
    cout << "\nSorted Array 2: ";
    displayArray(b4SIZE, add2);
    cout << "\n\n";

    
    //merge the arrays and display
    mergeArrays(mergeSIZE, add1, add2, dest);
    cout << "\nMerged Array: ";

    int dupeSize = checkDupe(mergeSIZE, dest);
    displayArray(dupeSize, dest);


    //clear the memory
    deleteArray(add1);
    deleteArray(add2);
    deleteArray(dest);
    
}


void allocateArray(int size, int* &arrAdd){
	arrAdd = new int[size];
}


void fillArray(int size, int* &arrAdd){
    for(int i = 0; i< size; i++){
        *(arrAdd + (i)) = (rand()%101);
    }
    
}

void displayArray(int size, int* &arrAdd){
    for (int i = 0; i < size; i++){
        if (i%10 == 0){
            cout << "\n";
        }
        cout << *(arrAdd + (i)) << ", ";
        
        }
}

void sortArray(int size, int* &arrAdd){
    int temp;
    for (int i = 0; i < size ; i++){
        int min = *(arrAdd + i);
        for(int j = i; j < size; j++){
            if (*(arrAdd + j) < min){
                min = *(arrAdd + j);
                temp = *(arrAdd + j);
                *(arrAdd + j) = *(arrAdd + i);
                *(arrAdd + i) = temp;
            }
        }
    }
}

int checkDupe(int size, int* &arrAdd){
    int j = 0;
    for (int i = 0; i < size - 1; i++) {
        if (arrAdd[i] != arrAdd[i + 1]) {
            arrAdd[j] = arrAdd[i];
            j++;
        }
    }

    arrAdd[j++] = arrAdd[size - 1];
    return j;
}

void mergeArrays(int size, int* &arrAdd1, int* &arrAdd2, int* &dest){
    //adds Array 1
    for (int i =0; i < size; i++){
        *(dest + i) = *(arrAdd1 + i);

    //checks if there is an address instead of int to see whether
    //Array 1 has ended yet. If it has, start adding array 2
        if(*(dest + i) > 100 || *(dest + i) < 0){
            int z = 0;
            while(i < size){
                *(dest + i) = *(arrAdd2 + z);
                i++;
                z++;
            }
            sortArray(size, dest);            
            break;
        }
    }
}



void deleteArray(int * &add){
    delete [] add;
    add = nullptr;
}







