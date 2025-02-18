#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;


template<typename T, typename U>
struct Element{
    T key;
    U data;
};

template<typename T, typename U>
struct Container{

    //default constructor
    Container(){
        vector<Element<T, U>, 16> vec;
    }
    
    //consturcotr for if they want a specific size
    Container(int num){
        vector<Element<T, U>, num> vec;
    }


    
};


int main(){
    Container <string,int> cc;
    Element <string,int> ee;


    return 0;
}