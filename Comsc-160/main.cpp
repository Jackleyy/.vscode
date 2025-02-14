/*************************************************************************************
Description:

Author: Justin Ackley
Assignment: PA1
Class: COMSC-110
Date: 09/5/2024
Status: Complete

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
        int min = NULL;
        for(int j = i; j < size-1; j++){
            if (*(arrAdd + j*4) < min){
                min = *(arrAdd + j*4);
                temp = *(arrAdd + j*4);
                *(arrAdd + j*4) = *(arrAdd + i*4);
                *(arrAdd + i*4) = temp;
            }
            else if (*(arrAdd + j*4) == min){
                //If I find one that is the same, i'll move the others to the left
                for (int z = j; z < size -1; z++){
                    arrAdd[i] = arrAdd[i + 1];
                }
                j--;
            }
        }
    }
}


int main() {
	int * add1 = NULL;
	allocateArray(3, add1);
    fillArray(3, add1);
    cout << "Array 1: ";
    displayArray(3, add1);
    sortArray(3, add1);
    cout << "\nSorted Array: ";
    displayArray(3, add1);
    cout << "\n";

    int *add2 = NULL;
    allocateArray(3, add2);
    fillArray(3, add2);
    cout << "\nArray 2: ";
    displayArray(3, add2);

}









