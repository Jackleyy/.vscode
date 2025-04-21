/*************************************************************************************
Description: This program makes a NEwstring class that acts just like the string class
             minus a few feautres. also adds ability to put int directly into string

Author: Justin Ackley
Assignment: PA2
Class: COMSC-110
Date: 10/22/2024
Status: Complete
Time spent: 5:27:00


************************************************************************************/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


const int SIZE = 100;

struct Newstring{

    int str_length;
    char *cp;

    //simple str_length function
    const int length(){
        if(cp[0] == '\0'){
            return 0;
        }
        return str_length;
    }



    //default constructor
    Newstring(){
        str_length = 0;
        cp = new char[SIZE];
    }

    //copy constructor for a literal
    Newstring(const char p[]){
        str_length = strlen(p);
        cp = new char[str_length +1];
        for (int i = 0; i < strlen(p); i++){
            cp[i] = p[i];
        }
        cp[str_length] = '\0';
    }

    //copy constructor for an object
    Newstring(Newstring &p){
        str_length = p.length();
        cp = new char[str_length +1];
        for (int i = 0; i < str_length; i++){
            cp[i] = p[i];
        }
        cp[str_length] = '\0';
    }

    //copy constructor for int
    Newstring(int p){
        string s = to_string(p);
        str_length = s.length();
        cp = new char[str_length +1];
        for (int i = 0; i < str_length; i++){
            cp[i] = s[i];
        }
        cp[str_length] = '\0';
    }

    //operator = overload to fill a string with a literal string
    Newstring& operator =(const char str[]){

        str_length = strlen(str);

        for (int i = 0; i < strlen(str); i++){
            cp[i] = str[i];
        }
        return *this;
    }

    //operator = overload to fill a string with another Newstring object
    Newstring& operator =(Newstring str){
        str_length = str.str_length;

        for (int i = 0; i < str.str_length; i++){
            cp[i] = str[i];
        }
        return *this;
    }

    //operator overload for an integer
    Newstring& operator =(int num){
        string s = to_string(num);
        str_length = s.length();

        for (int i = 0; i < str_length; i++){
            cp[i] = s[i];
        }
        cp[str_length] = '\0';
        return *this;
    }



    // [] overload so i can use cout
    const char operator[](const int num){
        if (num > str_length || num < 0){
            cout << "Array out of bounds";
            return ' ';
        }

        return cp[num];
    }

    // << overload
    friend ostream& operator<<(ostream& os, const Newstring& p) {
    for(int i = 0; i < p.str_length; i ++){
        os << p.cp[i];
    }
    return os;
}

    // == overlaod for an object
    bool operator ==(const Newstring& p){
        if (str_length != p.str_length){
            return false;
        }

        for(int i =0; i < str_length; i++){
            if (cp[i] != p.cp[i]){
                return false;
            }
        }
        return true;
    }

    // == overlaod for a literal
    bool operator ==(const char p[]){
        if (str_length != strlen(p)){
            return false;
        }

        for(int i = 0; i < str_length; i++){
            if (cp[i] != p[i]){
                return false;
            }
        }
        return true;
    }

    ~Newstring(){
        delete[] cp;
    }
};



int main(){

    //Test the creation of a new objetc
    cout << "\n" << "Test the creation of a new objetc" << endl;
    Newstring a;
    cout << a;

    //3. putting literal in an object
    cout << "\n" << "putting literal in an object" << endl;
    Newstring b;
    b = "yes";
    cout << b << endl;

    //2. putting obj in obj
    cout << "\n" << "putting obj in obj" << endl;
    Newstring c, d;
    c = "c";
    d=c;
    cout << d <<endl;

    //triple =
    cout << "\n" << "trple equals" << endl;
    d = c = b;
    cout << d <<endl;

    //1. str_length function
    cout << "\n" << "str_length function" << endl;
    cout << b.length() <<endl;
    cout << a.length() <<endl;

    //4. Square bracket overload
    cout << "\n" << "Square bracket overload" << endl;
    cout << b[2] << endl; //in bounds
    cout << b[-2] << endl; //out of bounds
    cout << b[5] << endl; //out of bounds

    //5a check if equals (==) operator overload with two objects
    cout << "\n" << "check if equals (==) operator overload with two objects" << endl;

    Newstring e, f, g;
    e = "Three";
    f = "three";
    g = "Three";

    if(e == f){
        cout << "Fail" <<endl;
    }
    else{
        cout << "true" << endl;
    }


    if(e == g){
        cout << "true" <<endl;
    }
    else{
        cout << "Fail" << endl;
    }

    //5b == operator with a literal
    cout << "\n" << "check if equals (==) operator overload with a literal c string array" << endl;

    if(e == "three"){
        cout << "Fail" <<endl;
    }
    else{
        cout << "true" << endl;
    }


    if(e == "Three"){
        cout << "true" <<endl;
    }
    else{
        cout << "Fail" << endl;
    }

    //Copy constructor with literal
    cout << "\n" << "Copy constructor with literal" << endl;

    Newstring h = "eigh";
    cout << h <<endl;

    //Copy constructor with object
    cout << "\n" << "Copy constructor with object" << endl;
    Newstring i = "eyeee";
    Newstring j = i;
    cout << j <<endl;

    //Copy constructor with integer
    cout << "\n" << "Copy constructor with int" << endl;
    Newstring k = 8;
    cout << k << endl;

    Newstring l = 878173694;
    cout << l << endl;

    //= overload with integer
    cout << "\n" << "= overload with integer" << endl;
    Newstring m, n;
    m = 1435;
    cout << m << endl;

    cout << m[3] << endl;

    n = 0;
    cout << n << endl;

    //check if null equals null
    cout << "\n" << "check if null equals null" << endl;

    Newstring no, note;
    no = '\0';
    note = '\0';

    if(no == note){
        cout << "two null strings equal each other" <<endl;
    }
    else{
        cout << "nah fam"<<endl;
    }



    return 0;
}
