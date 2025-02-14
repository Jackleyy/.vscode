#include <iostream>
using namespace std;


void fillArr(int *p);
void printArr(int *p);


int main(){
    int *p = new int[10]; //dyunamically allocates the array
    fillArr(p);
    printArr(p);

    delete p;
}


void fillArr(int* p){ //fills array with 1-100 integers
    for(int i = 0; i < 10 ; i++){
        p[i] = rand()%100;
    }
}

void printArr(int* p){ //prints the array while calculating even/odd count
    //variables for the odd/even count
    int even = 0;
    int odd = 0;

    //prints array with a space in between each
    cout << "Array contents: " << endl;
    for(int i = 0; i < 10; i++){
        cout << p[i] << " ";
        if (p[i] % 2 == 0){
            even++;
        }
        else{
            odd++;
        }
    }
    cout << endl;

    cout << "This array has a total of " << odd << " odd items and " << even << " even items." << endl;



}