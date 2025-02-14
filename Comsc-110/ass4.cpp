#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

/*************************************************************************************
Decription: This program will ask for input to get an array then sort the array.
After, it will display the information requested. 

Author: Justin Ackley
Class: COMSC-165
Date: 06/22/2024
Status: Complete
 
************************************************************************************/


int binSearch(array<int, 50>, int, int, int);

void bubSort(array<int, 50> &data, int limit){
    //naming it step to track how many times the sort happens
    for(int step = 0; step < limit; step++){
        for(int j = 0; j < limit - step; j++){
            if(data[j] > data[j+1]){
                swap(data[j], data[j+1]);
            }
        }
    }
}

int main(){
    //intializing variables
    int limit;
    int target;
    array<int,50> data;
    array<int,data.size()> sortedData;

    //Getting the array of data
    cout << "How many elements would you like to be sorted (1-50)? ";
    cin >> limit;

    for(int i = 0; i < limit; i++){
        cout << "Enter number " << i+1 << ": ";
        cin >> data[i];
    }

    //copying the array for later use
    for(int i = 0; i < limit; i++){
        sortedData[i] = data[i];
    }

    //sorting the data
    bubSort(sortedData, limit);

    //finding the target
    cout << "\nWhat number would you like to find? ";
    cin >> target;

    //displaying info

    cout << "\n\nSize of the array: " << sortedData.size(); //Size of array

    // original data
    cout << "\nOriginal Array: [";
    for(int i =0; i < limit; i++){
        cout << data[i] << ", ";
    }
    cout << "]";

    //Sorted Array
    cout << "\nSorted Array: [";
    for(int i =0; i < limit; i++){
        cout << sortedData[i] << ", ";
    }
    cout << "]";

    //target
    cout << "\nTarget value: " << target;

    //location of target in array
    cout << "\nIndex of target value in sorted array: " << binSearch(sortedData, 0, limit, target);

    //mean of data
    int total = 0;
    for(int i =0; i < limit; i++){
         total += data[i];
    }
    int mean = total/limit;
    cout << "\nMean of the array: " << mean;



    return 0;
}




/*
My attempt at a bubble sort. it will loop through the array
and keep putting the biigest item last until the array is sorted.
*/


int binSearch(array<int, 50> data, int low, int high, int target){
    int mid = low + (high-low) / 2;
    if(high >= low){
        if(data[mid] == target){
            return mid;
        }
        else if(data[mid] > target){
            return binSearch(data, low, mid - 1, target);
        }
        else{
            return binSearch(data, mid + 1, high, target);
            
        }
    }
    return - 1;
}