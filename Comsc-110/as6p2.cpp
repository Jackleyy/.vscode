#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


/*************************************************************************************
Decription: This program will prompt a user for a sentence and then translates it into piglatin
the method is:
- get word(s)
- add a space at the end of the last word
- seperate them by finding any spaces after a word ends
- transa=late each word seperately and then add it to a new string
- print out the new string

NOTE: My translations look slightly different than the example given due to a differing ruleset of translation
        I found mine on a website which didnt match your example.

Author: Justin Ackley
Class: COMSC-165
Date: 06/22/2024
Status: Complete
 
************************************************************************************/

//prototypes
string getStr(); //Gets a word from the user
string translate(string);
bool isVowel(string, int);


int main(){
    string str, word, trans;

    str = getStr();

    cout << "\nBefore translation: " << str;

    for(int i = 0; i < str.size() - 1; i++){ //breaks the phrase into words and translates them
        if(str[i] == ' '){
            word = str.substr(0,i);//grabs a word before the space
            trans.append(translate(word) + " ");
            str.erase(0,i+1); //deletes the tranlasted word from the string
            i = 0;// sets i back to zero so it can translate the rest of the words
        }
    }

    cout << "\nAfter translation: " << trans;




    return 0;
}

//Gets a word from the user
string getStr(){
    string str;
    cout << "Enter a string to be translated: ";
    getline(cin, str);

    while(str[str.size()-1] == ' '){//removes any excess spaces from endso translation goes smoothly
        str.erase(str.size()-1);
    }

    str.append("  ");//add a final space so the translate function workes on the last word of a string

    return str;
}

string translate(string word){

    if (isVowel(word, 0) == true){//If the word starts with a vowel, just add "ay" to it
        word.append("yay");
        return word;
    }
    else{//If it starts with a consonant we need to see how many consonants it starts with
        string start;
        for(int i = 1; i < word.length(); i++){
            if(isVowel(word, i) == true || word[i] == 'y'){
                start = word.substr(0,i); //if a vowel is found, start is set to all the consonants in the beggingin of the word
                word.erase(0,i); //deletes all the starting consonants
            }
            else{   //continues until a vowel is found
                continue;
            }
        }
        
        word.append(start + "ay");
        
        return word;
    }
}

bool isVowel(string word, int start){
    char letter = tolower(word[start]);
    if(letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u'){
        return true;
    }
    else{
        return false;
    }
}