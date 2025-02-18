#include <iostream>
#include <vector>
using namespace std;

struct clase{
    int x = 0;
    string y = "worked";

};

struct Student :public clase{

};


int main(){

    clase * cp;
    cp = new clase;

    

    vector<string>* sp;
    sp = new vector<string>;

    Student john;

    cout << john.y;

    return 0;
}