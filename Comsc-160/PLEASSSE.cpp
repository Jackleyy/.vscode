#include <iostream>
#include <cstring>
using namespace std;
/*Code a complete class definition that you would place into a header file for a class named Toaster. It has
private members numSlices (int), model (string), and price (float). It has a getter for price and a setter for
numSlices. It has a constructor with one int parameter. The constructor uses the parameter to set the
numSlices member. You may code the constructor in-line or out-of-line, your choice. */



class Sample
{
public:
float price1;
float price2;
float * oldPrices;
Sample();
};

/*Code a complete out-of-line function definition for the default constructor for class Sample. The constructor
should initialize any numeric fields to zero, and also allocate an array of 100 floats using the member which is
a pointer.*/


Sample::Sample(){
    price1 = 0;
    price2 = 0;
    oldPrices = new float[100];
}


class ABC {
public:
int a = 0;
int add2 (int, int);
};
int ABC::add2 (int x, int y)
{
this->a += x;
cout << "we're at point a" << endl;
cout << this <<endl;
return 0;
}


class Toaster{
    int numSlices;
    string model;
    float price;

    public:
    Toaster(int s){
        numSlices = s;
    }
    float getPrice(){
        return price;
    }

    void setSlices(int num){
        numSlices = num;
    }
};
    
class Ink{
    public:
    int colorCode;
    int brightness;
};


class G1 {
private:
int a;
protected:
int b =10;
public:
int c;

int getb(){
    return b;
}
};

class G2 : public G1 {

};

class Theclass {
private:
int a;
int b;
int c;

public: 
    void setA(int x){
        a = x;
    }

    int getA(){
        return a;
    }

};



 int main(){

/*int a = 10;
int * b;
int c;
b = &a;
c = (*b) + 1;
//int *d = *b;

cout << a << endl;

cout << b << endl;

cout << c << endl;*/


/*Ink object1;
Ink *w;
w = new Ink;

/*Put the value 100 into the brightness member for the dynamically allocated object.
Put the value 5 into the colorCode member for the statically allocated object.

w->brightness = 100;
object1.colorCode =5;

cout << w->brightness << endl;
cout << object1.colorCode <<endl;
*/

/*Ink * m;
m = new Ink;
Ink * e;
m = new Ink;

G1 yo;

cout << yo.getb();*/


/*Theclass x;
Theclass y;

y.setA(15);

x = y;

cout << x.getA();

return 0;*/

/*ABC one;
cout << &one <<endl;
int z = one.add2 (3, 4);
cout << one.a <<endl;*/





return 0;

}