/*************************************************************************************
Description: This program uses maps to make a container that has keys and data

Author: Justin Ackley
Assignment: PA6
Class: COMSC-110
Date: 11/3/2024
Status: Complete
Time spent: 2:43:00


************************************************************************************/
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

    Element<T, U>* arr;
    int maxSize = 0;
    int size = 0;
    bool isAccessed = false;
    int curPos= 0;


    //default constructor
    Container(){
        arr = new Element<T, U>[16];
        maxSize = 16;
    }

    //consturcotr for if they want a specific size
    Container(int num){
        arr = new Element<T, U>[num];
        maxSize = num;
    }

    //functions
    void push_back(Element<T, U> x){
        if(size >= maxSize){
            throw "container full";
        }
        isAccessed = true;
        arr[size] = x;
        size++;
    }

    Element<T, U> front(){
        if (!isAccessed){
            throw "container empty";
        }
        return arr[0];
    }

    Element<T, U> back(){
        if (!isAccessed){
            throw "container empty";
        }
        return arr[size];
    }

    int get_size(){
        return size;
    }

    int max_size(){
        return maxSize;
    }

    void start(){
        if (!isAccessed){
            throw "container empty";
        }
        curPos = 0;
    }

    Element<T,U> get_next(){

        if (!isAccessed){
            throw "container empty";
        }
        if(curPos >= size){
            throw "end of container";
        }
        curPos++;
        return arr[curPos -1];
    }

    Element<T, U> operator [](const char* s){
        for(int i=0; i <= size; i++){
            if (arr[i].key == s){
                curPos = i;
                return arr[i];
            }
        }
        throw "Key not found";
    }


};


int main(){
	Container <string,int> cc;
	Element <string,int> ee;
	cout << "*** starting test"<< endl;
	ee.key = "aaa";
	ee.data = 111;
	cc.push_back(ee);
	ee.key = "bbb";
	ee.data = 222;
	cc.push_back(ee);
	ee.key = "ccc";
	ee.data = 333;
	cc.push_back(ee);
	ee.key = "ddd";
	ee.data = 444;
	cc.push_back(ee);
	ee.key = "eee";
	ee.data = 555;
	cc.push_back(ee);
	ee.key = "fff";
	ee.data = 666;
	cc.push_back(ee);
	cout << "max size " << cc.max_size() << endl;
	cout << "current size " << cc.get_size() << endl;
	cc.start();
	cout << "*** iteration through all elements" << endl;
	try
	{
		while (true)
		{
			ee = cc.get_next();
			cout << ee.key << "*" << ee.data << endl;
		}
	}
	catch (const char s[])
	{
		cout <<"end of container reached -->" << s << "<--" << endl;
	}
	cout << "*** direct retrieval of key bbb" << endl;
	ee = cc["bbb"];
	cout << ee.key << "*" << ee.data << endl;
	cout << "*** direct retrieval of key abc" << endl;
	try
	{
		ee = cc["abc"];
	}
	catch (const char s[])
	{
		cout << "key not found condition -->" << s << "<--" << endl;
	}
	cout << "*** direct retrieval of key ddd" << endl;
	ee = cc["ddd"];
	cout << ee.key << "*" << ee.data << endl;
	cout << "*** iteration from that point forward" << endl;
	try
	{
		while (true)
		{
			ee = cc.get_next();
			cout << ee.key << "*" << ee.data << endl;
		}
	}
	catch (const char s[])
	{
		cout <<"end of container reached -->" << s << "<--" << endl;
	}





    return 0;
}
