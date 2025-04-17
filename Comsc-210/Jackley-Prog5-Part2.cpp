#include <Jackley-Prog5-Part1.h>
#include <iomanip>
#include <iostream>

using namespace std;

int main(){

    int SIZE = 10;
    int rarray[SIZE]; 

    //fils array of random size with random ints
    for(int i = 0; i <= SIZE; i++){
        rarray[i] = rand()%100;
    }

    //construct heap with array

    myHeap<int> heap(rarray,SIZE);
    for(int i = SIZE; i <= SIZE; i++){
        cout << "top of heap: " << heap.peekTop() << endl;
        cout << "removing"  << endl;
        heap.remove();
    }


    myHeap<int> coolHeap = myHeap<int>();

    for(int i = SIZE; i <= SIZE; i++){
        cout << "top of cool heap: " << coolHeap.peekTop() << endl;
        cout << "adding"  << endl;
        heap.add(rand()%100);
    }

    myHeap<int> heap(rarray,SIZE);
    for(int i = SIZE; i <= SIZE; i++){
        cout << "op of cool heap: " << coolHeap.peekTop() << endl;
        cout << "removing"  << endl;
        heap.remove();
    }






    return 0;
}