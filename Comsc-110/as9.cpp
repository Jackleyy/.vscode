/*************************************************************************************
Decription: This program utilizes linked lists to keep an ordered list of numbers.
            The program allows the user to do a few functions to edit and view
            the list

Author: Justin Ackley
Class: COMSC-165
Date: 07/17/2024
Status: Complete
 
************************************************************************************/
#include <iostream>
using namespace std;


//structure for a node
struct Node{
    int val;
    Node* next;

    Node(int x){
        val = x;
        next = nullptr;
    }
};


struct linkedList{
private:
    Node* head;

public:
    //initializes an empty list
    linkedList(){
        head = nullptr;
    }


    void add(int x){
        Node* newNode = new Node(x);

        if(x == -1){
            cout << "\nEnding the add feature\n";
            return;
        }
        else if(x < -1){
            cout << "\nInvalid choice please enter another number";
            return;
        }

        //checking if x is already in the list
        Node* current = head;
        while(current != nullptr){
            if(current->val == x){
                cout << "\nNumber is already in the list, try again\n";
                return;
            }
        current = current->next;
        }

        //checkingif the node needs to be placed at position 1
        if(head == nullptr || x < head->val){
            newNode->next = head;
            head = newNode;
            return;
        }

        //pointer to track where to put our value
        current = head;
        while(current->next != nullptr && current->next->val < x){
            current = current->next;
        }

        //inserting the node now that we know the correct position 
        newNode->next = current->next;//wherever current lands, we know newNode has to point the next objectin the list
        current->next = newNode;//current is pointing to whatever object it is currently on thus it can modify the values inside
        return;
    }

    void remove(int x){
        if (head != nullptr && head->val == x) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while(current->next != nullptr && current != nullptr){
            if(current->next->val == x){
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
        current = current->next;
        }
    }

    void print(){
        Node* current = head;

        cout << "Current list: ";
        cout << "{";
        while(current != nullptr){
            cout << current->val << ", ";
            current = current->next;
        }
        cout << "}";
    }


    void search(int num){
        Node* current = head;
        int index = 0;
        while(current != nullptr){
            if(current->val == num){
                cout << "\nNumber found at position " << index;
                return;
            }
            index++;
            current = current->next;
        }
        cout << "\nNumber not found, try again\n";
    }
};


int main(){
    linkedList li;
    int input; //for the add fucntion
    int choice; // for the switch function
    int num; //for case 3 and 4

    
    while(choice != 5){
        cout << "\n\nWhat would you like to do?\n1. Add a number to the list\n2. Print the current list";
        cout <<  "\n3. Delete an item from the list\n4. Search for a number\n5. End the program" << endl;
        cin >> choice;
        switch(choice){
            case 1:
                input = 0;
                while(input != -1){
                    cout << "\n\nWhat number would you like to add to the list? ";
                    cin >> input;
                    li.add(input); 
                    li.print();
                }
                break;
            case 2:
                li.print();
                break;
            case 3:
                li.print();
                cout << "\nWhat number would you like to remove? ";
                cin >> num;
                li.remove(num);
                li.print();
                break;
            case 4:
                cout << "\nWhat number would you like to search for? ";
                cin >> num;
                li.search(num);
                break;
            case 5:
                cout << "\nGoodbye!";
                break;
            default:
                cout << "\nInvalid choice, try again";
                break;
        }
    }
    return 0;
}