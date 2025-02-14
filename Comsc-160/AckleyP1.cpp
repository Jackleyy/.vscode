/*************************************************************************************
Description:

Author: Justin Ackley
Assignment: PA1
Class: COMSC-110
Date: 09/5/2024
Status: Complete

    *(arrAdd + (7*4)) = 97;
    *(arrAdd + (3*4)) = 97;
    *(arrAdd + (0*4)) = 97;

************************************************************************************/

#include <iostream>
using namespace std;

void allocateArray(int size, int* &arrAdd){
	int* pArray = new int[size];
	arrAdd = pArray;
}


void fillArray(int size, int* arrAdd){
    for(int i = 0; i< size; i++){
        *(arrAdd + (i*4)) = (rand()%101);
    }
    
}

void displayArray(int size, int* arrAdd){
    for (int i = 0; i < size; i++){
        cout << *(arrAdd + (i*4)) << ", ";
    }
}

void sortArray(int size, int* arrAdd){
    int temp;
    for (int i = 0; i < size ; i++){
        int min = *(arrAdd + i*4);
        for(int j = i; j < size; j++){
            if (*(arrAdd + j*4) < min){
                min = *(arrAdd + j*4);
                temp = *(arrAdd + j*4);
                *(arrAdd + j*4) = *(arrAdd + i*4);
                *(arrAdd + i*4) = temp;
            }
        }
    }
}

void mergeArrays(int size, int* arrAdd1, int* arrAdd2, int* dest){
    //adds Array 1
    for (int i =0; i < size; i++){
        *(dest + i*4) = *(arrAdd1 + i*4);

    //checks if there is an address instead of int to see whether
    //Array 1 has ended yet. If it has, start adding array 2
        if(*(dest + i*4) > 100){
            int z = 0;
            while(i < size){
                *(dest + i*4) = *(arrAdd2 + z*4);
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

int main() {
	int * add1 = NULL;
	allocateArray(9, add1);
    fillArray(9, add1);
    cout << "Array 1: ";
    displayArray(9, add1);
    sortArray(9, add1);
    cout << "\nSorted Array 1: ";
    displayArray(9, add1);
    cout << "\n";

    int *add2 = NULL;
    allocateArray(5, add2);
    fillArray(5, add2);
    cout << "\nArray 2: ";
    displayArray(5, add2);
    sortArray(5, add2);
    cout << "\nSorted Array 2: ";
    displayArray(5, add2);
    cout << "\n";

    
    
    int *dest = NULL;
    allocateArray(14, dest);
    mergeArrays(14, add1, add2, dest);
    cout << "\nMerged Array: ";
    displayArray(14, dest);

    deleteArray(add1);
    deleteArray(add2);
    deleteArray(dest);
    
}









