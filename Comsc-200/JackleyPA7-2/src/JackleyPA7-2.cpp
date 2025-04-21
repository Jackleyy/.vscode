/*************************************************************************************
Description: Management of different inhertied classes. Use of virtual functions and
             polymorphism

Author: Justin Ackley
Assignment: PA7-2
Class: COMSC-110
Date: 11/21/2024
Status: Complete
Time spent: 3:55:35


************************************************************************************/

#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


class Vehicle{
protected:
    string ID;
    string manufacturer;
    string start_of_service;
    int capacity;
    char status;

public:
    virtual void display(){

    }

    void commonDisplay(){
        cout << "ID: " << ID << endl;
        cout << "manufacturer: " << manufacturer << endl;
        cout << "start_of_service: " << start_of_service << endl;
        cout << "capacity: " << capacity << endl;
        cout << "status: " << status << endl;
    }

    virtual void checkM(){

    }
    string getID(){
        return ID;
    }
};

class Bus : public Vehicle{
private:
    int miles_since_check;
    string tire_size;
    char fuel_type;

public:
    Bus(string ID, string manufacturer, string start_of_service, int capacity,
        char status, int miles_since_check, string tire_size, char fuel_type){

        this->ID = ID;
        this->manufacturer = manufacturer;
        this->start_of_service = start_of_service;
        this->capacity = capacity;
        this->status = status;

        this->miles_since_check = miles_since_check;
        this->tire_size = tire_size;
        this->fuel_type = fuel_type;
        }

    virtual void display(){
        cout << "\n\nNew vehicle object:" << endl;
        commonDisplay();

        cout << "miles_since_check: " << miles_since_check << endl;
        cout << "tire_size: " << tire_size << endl;
        cout << "fuel_type: " << fuel_type << endl;
    }

    virtual void checkM(){
        //see if its in maintence mode
        if(status == 'M'){
            cout << "Vehicle is currently in maintence mode, please take to the nearest dealership" << endl;
        }
        else if(miles_since_check >= 25000){ //see if it needs to be switched to maintenec mode
            cout << "Bus is in need of maintnence, please seek the nearest dealership.\nSwitching to maintnence mode"  << endl;
            status = 'M';
        }

    }

    };


class Railcar : public Vehicle{
private:
    int on_time_since_check;
    char motor_type;
    int motor_voltage;

public:
    Railcar(string ID, string manufacturer, string start_of_service, int capacity,
    char status, int on_time_since_check,char motor_type, int motor_voltage){
        this->ID = ID;
        this->manufacturer = manufacturer;
        this->start_of_service = start_of_service;
        this->capacity = capacity;
        this->status = status;

        this->on_time_since_check = on_time_since_check;
        this->motor_type = motor_type;
        this->motor_voltage = motor_voltage;

    }

    virtual void display(){
        cout << "\n\nNew vehicle object:" << endl;
        commonDisplay();

        cout << "on_time_since_check: " << on_time_since_check << endl;
        cout << "motor_type: " << motor_type << endl;
        cout << "motor_voltage: " << motor_voltage << endl;
    }

    virtual void checkM(){
        //see if its in maintence mode
        if(status == 'M'){
            cout << "Vehicle is currently in maintence mode, please take to the nearest dealership" << endl;
        }
        else if(on_time_since_check >= 25000){ //see if it needs to be switched to maintenec mode
            cout << "Railcar is in need of maintnence, please seek the nearest dealership.\nSwitching to maintnence mode" << endl;
            status = 'M';
        }

    }
};

class autoCab : public Vehicle{
private:
    int miles_since_check;
    int hours_on_battery;
    int software_level;

public:
    autoCab(string ID, string manufacturer, string start_of_service, int capacity,
    char status, int miles_since_check, int hours_on_battery, int software_level){
        this->ID = ID;
        this->manufacturer = manufacturer;
        this->start_of_service = start_of_service;
        this->capacity = capacity;
        this->status = status;

        this->miles_since_check = miles_since_check;
        this->hours_on_battery = hours_on_battery;
        this->software_level = software_level;
    }

    virtual void display(){
        cout << "\n\nNew vehicle object:" << endl;
        commonDisplay();

        cout << "miles_since_check: " << miles_since_check << endl;
        cout << "hours_on_battery: " << hours_on_battery << endl;
        cout << "software_level: " << software_level << endl;
    }

    virtual void checkM(){
        //see if its in maintence mode
        if(status == 'M'){
            cout << "Vehicle is currently in maintence mode, please take to the nearest dealership" << endl;
        }
        else if(miles_since_check >= 500 || hours_on_battery >= 750){ //see if it needs to be switched to maintenec mode
            cout << "Cab is in need of maintnence, please seek the nearest dealership.\nSwitching to maintnence mode" << endl;
            status = 'M';
        }

    }

};



int main(){

    //opening file and checking if it is valid
    ifstream infile;
    infile.open("a7dataF24.txt");

    if(!infile.is_open()){
        cout << "Error opening the file, please retry" << endl;
        return 1;
    }

    vector<Vehicle*> list;


    //reading the file and instantiating objects of different types
    char type;
    string line;
    while(getline(infile, line)){
        type = line[0];

        switch(type){
            case 'B':
                {
                string ID = line.substr(0, 5);
                string manufacturer = line.substr(5, 15);
                string start_of_service = line.substr(20, 8);
                int capacity = stoi(line.substr(28, 3));
                char status = line[31];
                int miles_since_check = stoi(line.substr(32, 6));
                string tire_size = line.substr(39, 9);
                char fuel_type = line[48];

                list.push_back(new Bus(ID, manufacturer, start_of_service, capacity,
                           status, miles_since_check, tire_size, fuel_type));



                break;
                }

            case 'R':
                {
                string ID = line.substr(0, 5);
                string manufacturer = line.substr(5, 15);
                string start_of_service = line.substr(20, 8);
                int capacity = stoi(line.substr(28, 3));
                char status = line[31];
                int on_time_since_check = stoi(line.substr(32, 3));
                char motor_type = line[35];
                int motor_voltage = stoi(line.substr(36, 4));

                list.push_back(new Railcar(ID, manufacturer, start_of_service, capacity,
                               status, on_time_since_check, motor_type, motor_voltage));

                break;
                }
            case 'C':
                {

                string ID = line.substr(0, 5);
                string manufacturer = line.substr(5, 15);
                string start_of_service = line.substr(20, 8);
                int capacity = stoi(line.substr(28, 3));
                char status = line[31];
                int miles_since_check = stoi(line.substr(32, 4));
                int hours_on_battery = stoi(line.substr(36, 4));
                int software_level = stoi(line.substr(40, 5));


                list.push_back(new autoCab(ID, manufacturer, start_of_service, capacity,
                               status, miles_since_check, hours_on_battery, software_level));
                break;

                }
        }
    }

    for(int i = 0; i < list.size(); i++){

        list[i]->display();

    }



    string id;
    Vehicle* currentV;
    while(id != "00000"){
        cout << "\n\nPlease enter a vehicle ID" << endl;
        cin >> id;


        if(id == "00000"){
            cout << "Goodbye";

            for(int i = 0; i < list.size(); i++){
                list[i]->display();
            }
            return 2;
        }


        for(int i = 0; i < list.size(); i++){
            if(id == list[i]->getID()){
                currentV = list[i];
                currentV->display();
                currentV->checkM();
                break;
            }
            else if(i == list.size()){
                cout << "Vehicle not found, try again" << endl;
                return 3;
            };
        }

    }

}
