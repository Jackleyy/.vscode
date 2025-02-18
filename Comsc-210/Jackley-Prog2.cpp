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


    int num; // tells how many lines to read
    int index = 1; //will tell when to clear the stack for the next test; set to one because the continue will skip index++
    string tell; //instruction; either i or r
    stack<string> sab; //stack for the strings  
    string temp; //for placing the popped string into for checking purposes
    bool stack = true; //if it is a stack or not


    //issue is because when we say its not a stack, it skips
    //the rest of the code and therefore index will never match
    while(getline(test, myText)){
      //if it is a number it will be put in num, if its not a number it must be 
      //a string to decipher so the first letter will be the instruction

      if(is_number(myText)){ //if nuymber, skip the rest of the code
        num = stoi(myText);
        index = 0;
        stack = true;
        continue;
      }
      else{ //if not number, read the instruction and word
        tell = myText.substr(0,1);
        temp = myText.substr(2);
        index++;
      }


      //checks if it has reach end of desired readings, resets eveerything, makes sure 
      //code doesnt run again so false positive doesnt exist
      
      if (index == num){ //problem occurs because 
        sab.pop();
        //check the result of the stack
        if(stack && sab.empty()){
          cout << "stack" << endl;
        }
        else{
          cout << "not stack" << endl;
          continue;
        }
        index = 1;

        //clearing the stack
        while(!sab.empty()){
          sab.pop();
        }
        continue;
      }


      if (stack == false){
        sab.pop();
        continue;
      }



      //we have instruction, use logic to compare the pops
      if(tell == "i"){
        sab.push(temp);
      }
      else if (tell == "r"){
        if(temp != string(sab.top())){
          stack = false;
        }
        else{
          stack = true; 
        }
        sab.pop();
         
      }
        
    }



    test.close(); //closing the file

    return 0;

    

}

//stole from stack overflow
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}