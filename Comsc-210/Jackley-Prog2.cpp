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

    while(getline(test, myText)){
      int num;
      string tell;
      stack<string> sab;
      

      //if it is a number it will be put in num, if its not a number it must be 
      //a string to decipher so the first letter will be the instruction
      if(is_number(myText)){
        num = stoi(myText);
        cout << num;
      }
      else{
        tell = myText.substr(0,1);
        cout << tell;
      }

      
      if(tell == "i"){
        sab.push(myText.substr(2));
      }
      else if (tell == "r"){
        
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