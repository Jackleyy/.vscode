#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

int syr(int num, int lim, int & highestNum);
int syr2(int num, int lim, int & highestNum);


int main(){
    int numStart;
    int numLimit;
    int highNum;
    bool startInvalid = true;
    bool limitInvalid = true;

    while (startInvalid){
        cout << "Enter the starting number : ";
        cin >> numStart;
        cout << endl;
        if(numStart > 0){
            startInvalid = false;
        }
    }
    
    while (limitInvalid){
        cout << "Enter the limit of terms: ";
        cin >> numLimit;
        cout << endl;
        if(numLimit > 0){
            limitInvalid = false;
        }
    }

    

    
    /*
    
    if(syr(numStart, numLimit, highNum) != 1){
        cout << "Sequence was aborted early" << endl;
    }
        
    */

    if(syr2(numStart, numLimit, highNum) != 1){
        cout << "Sequence was aborted early" << endl;
    }

    cout << "Highest number reached: " << highNum;
    return 0;
}


int syr(int num, int lim, int & highestNum){
    //checking if current num is bigger than highest num
    if (num >= highestNum){
        highestNum = num;
    }

    //determining if limit is reacehd
    if (lim == 0){
        return num;
    }

    //syracuse sequence calculations and recursion
    if(num == 1){
        cout << 1 << endl;
        return 1;
    }
    else if(num%2 == 0){
        cout << num << endl;
        return syr(num/2, lim-1, highestNum);
    }
    else{
        cout << num << endl;
        return syr(((num*3)+1)/2, lim-1, highestNum);
    } 
    
    
}

int syr2(int num, int lim, int & highestNum){
    while(lim != 0){
        if(num == 1){
            cout << 1 << endl;
            return 1;
        }
        else if(num%2 == 0){
            cout << num << endl;
            num = num/2;
            lim = lim -1;
        }
        else{
            cout << num << endl;
            num = ((num*3)+1)/2;
            lim = lim -1;
        }
        if (num >= highestNum){
            highestNum = num;
        }
    }
    return num;
}