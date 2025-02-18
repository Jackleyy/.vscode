#include <iomanip>
#include <iostream>
#include <stack>
#include <fstream>
#include <string>
using namespace std;

int main(){
    /*
        ok so my approach should go something like this
            - I know that I need a stack that will
              - insert when given i
              - remove when given r
              - only loop for a given int amount of times
            - I need to compare this stacks pop function 
              with the value of the given r command
            - program should fail if it doesnt reach i either
        
        pseudo code:
          - set num = int
          - loop i < num times to account for each i and r 
          - check if i, if r then switch to pop section
          - make stack given the i commands
          - pop through stack and compare pops to r values
          - set boolean to false if fails and break loop
          - if loop ends with stack[i+1] != null then false
              
    */
    ofstream test("test.txt");
    string myText;

    while(getline(test, myText)){

    }



    test.close();

    return 0;



}