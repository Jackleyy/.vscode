#include <iostream>
#include <stdexcept>
using namespace std;


int theFunc(int x){
    cout << "in the func";
    x += 1;
}

int main(){

theFunc(2);

catch(invalid_argument){
    cout << "caught it";

}

cout << "made it";
    return 0;
}