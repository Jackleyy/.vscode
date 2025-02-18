#include <iostream>
#include <cstdlib>
using namespace std;

void allocateArray(int size, int* &arrAdd){
    arrAdd = new int[size];
}

void fillArray(int size, int* arrAdd){
    for(int i = 0; i < size; i++){
        arrAdd[i] = (rand() % 101);
    }
}

void displayArray(int size, int* arrAdd){
    for (int i = 0; i < size; i++){
        cout << arrAdd[i] << ", ";
    }
}

void sortArray(int size, int* arrAdd){
    for (int i = 0; i < size - 1; i++){
        for(int j = i + 1; j < size; j++){
            if (arrAdd[j] < arrAdd[i]){
                swap(arrAdd[i], arrAdd[j]);
            }
        }
    }
}

void mergeArrays(int size1, int* arrAdd1, int size2, int* arrAdd2, int* dest){
    int i = 0, j = 0, k = 0;
    while (i < size1 && j < size2) {
        if (arrAdd1[i] <= arrAdd2[j]) {
            dest[k++] = arrAdd1[i++];
        } else {
            dest[k++] = arrAdd2[j++];
        }
    }
    while (i < size1) {
        dest[k++] = arrAdd1[i++];
    }
    while (j < size2) {
        dest[k++] = arrAdd2[j++];
    }
}

void deleteArray(int * &add){
    delete [] add;
    add = nullptr;
}

int main() {
    int size1 = 9, size2 = 5;
    int *add1 = nullptr;
    int *add2 = nullptr;
    int *dest = nullptr;

    allocateArray(size1, add1);
    fillArray(size1, add1);
    cout << "Array 1: ";
    displayArray(size1, add1);
    sortArray(size1, add1);
    cout << "\nSorted Array 1: ";
    displayArray(size1, add1);
    cout << "\n";

    allocateArray(size2, add2);
    fillArray(size2, add2);
    cout << "\nArray 2: ";
    displayArray(size2, add2);
    sortArray(size2, add2);
    cout << "\nSorted Array 2: ";
    displayArray(size2, add2);
    cout << "\n";

    int mergedSize = size1 + size2;
    allocateArray(mergedSize, dest);
    mergeArrays(size1, add1, size2, add2, dest);
    cout << "\nMerged Array: ";
    displayArray(mergedSize, dest);
    cout << "\n";

    deleteArray(add1);
    deleteArray(add2);
    deleteArray(dest);

    return 0;
}