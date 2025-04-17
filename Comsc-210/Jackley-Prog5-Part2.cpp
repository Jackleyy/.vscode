#include "Jackley-Prog5-Part1.h"
#include <iomanip>
#include <iostream>

using namespace std;

int main(){
    cout << std::boolalpha; // Enable boolalpha flag
    int SIZE = 10;
    int rarray[SIZE -1]; 

    //fils array of random size with random ints
    for(int i = 0; i <= SIZE; i++){
        rarray[i] = rand()%100;
    }



    //construct heap with array
    myHeap<int> heap(rarray,SIZE);

    cout << "Existing array test: " << endl;
    cout << string(20, '-') << endl;
    cout << "Number of nodes: " << heap.getNumberOfNodes() << " (isEmpty() is " << heap.isEmpty() << ")" << endl;
    cout << "random array: "; 
    for(int i = 0; i < SIZE; i++){
        cout << rarray[i] << " ";
    }

    cout << "\n10 removes: ";
    for(int i = 0; i < SIZE; i++){
        cout << heap.peekTop() << " ";
        heap.remove();
    }


    myHeap<int> coolHeap = myHeap<int>();
    for(int i = 0; i <= SIZE; i++){
        rarray[i] = rand()%100;
    }

    cout << "\n\nEmpty array test: " << endl;
    cout << string(20, '-') << endl;
    cout << "random array: "; 
    for(int i = 0; i <= SIZE; i++){
        cout << rarray[i] << " ";
    }

    
    cout << "\nNumber of nodes: " << coolHeap.getNumberOfNodes() << " (isEmpty() is " << heap.isEmpty() << ")" <<endl;

    for(int i = 0; i <= SIZE; i++){
        coolHeap.add(rand()%100);
    }

    cout << "10 removes: ";
    for(int i = 0; i <= SIZE; i++){
        cout << coolHeap.peekTop() << " ";
        coolHeap.remove();
    }






    return 0;
}