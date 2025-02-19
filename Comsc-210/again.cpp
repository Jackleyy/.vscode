#include <iomanip>
#include <iostream>
#include <stack>
#include <fstream>
#include <string>
using namespace std;

bool is_number(const std::string&);

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
    ifstream test("test.txt");
    string myText;

    int num = 0;      // tells how many lines to read
    int index = 1;    // will tell when to clear the stack for the next test; set to one because the continue will skip index++
    string tell;      // instruction; either i or r
    stack<string> sab; // stack for the strings  
    string temp;      // for placing the popped string into for checking purposes
    bool stack = true; // if it is a stack or not

    while(getline(test, myText)){
        // if it is a number, it will be put in num; if it's not a number it must be 
        // a string to decipher so the first letter will be the instruction
        if(is_number(myText)){ // if number, start a new test case
            num = stoi(myText);
            index = 0;
            stack = true;
            // clearing the stack for a new test case
            while(!sab.empty()){
                sab.pop();
            }
            continue;
        }
        else { // if not a number, read the instruction 
            tell = myText.substr(0,1);
            // get the word part from position 2 to the end
            temp = myText.substr(2);
            index++;
        }

        // we have instruction, use logic to process the command
        if(tell == "i"){
            sab.push(temp);
        }
        else if (tell == "r"){
            if(sab.empty() || sab.top() != temp){
                stack = false;
            }
            else{
                sab.pop();
            }
        }
        else{
            cout << "invalid character for reading, must be 'i' or 'r' " << endl;
            stack = false;
            // break out of processing this test case by skipping further commands
            // (could also use a while loop to skip commands until index == num)
        }

        // checks if it has reached the end of desired readings, resets everything, 
        // makes sure code doesn't run again so false positive doesn't exist
        if (index == num){
            // if there is any leftover in the stack, it's not a proper stack
            if(!sab.empty()){
                stack = false;
            }
            cout << (stack ? "stack" : "not stack") << endl;
            index = 1;
            // clear the stack for the next test case
            while(!sab.empty()){
                sab.pop();
            }
        }
    }

    test.close();
    return 0;
}

//stole from stack overflow
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}
