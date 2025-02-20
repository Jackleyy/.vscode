/*************************************************************************************
Description:

Author: Justin Ackley
Assignment: PA7
Class: COMSC-110
Date: 11/12/2024
Status: Complete
Time spent:


************************************************************************************/

#include <iostream>
#include <vector>
using namespace std;


class vehicle{
protected:
    string ID;
    string manufacturer;
    string start_of_service;
    int capacity;
    char status;


};

class Bus : private vehicle{
private:
    int miles_since_check;
    string tire_size;
    char fuel_type;

};

class Railcar : private vehicle{
private:
    int on_time_since_check;
    char motor_type;
    int motor_voltage;

};

class autoCab : private vehicle{
private:
    int miles_since_check;
    int hours_on_battery;
    int software_level;

};


int main(){


}
