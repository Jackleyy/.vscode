#include <iostream>
#include <iomanip>
using namespace std;

void getTemps(int[], int &);
void bubSort(int[], int);
double median(int[], int);

int main(){
    int temps[10];
    int limit;

    getTemps(temps, limit);
    bubSort(temps, limit);

    cout << "\nmedian: " <<setprecision(2)<< fixed<< median(temps, limit);


    return 0;
}


void getTemps(int temps[], int &limit){
    int input;

    cout << "How many temperatures would you like to input (1-10)? ";
    cin >> limit;

    for(int i =0; i < limit; i++){
        cout << "\nEnter temperature " << i+1 << ": ";
        cin >> input;
        temps[i] = input;
    }
}

/*
My attempt at a bubble sort. it will loop through the array
and keep putting the biigest item last until the array is sorted.
*/
void bubSort(int data[], int limit){
    //naming it step to track how many times the sort happens
    for(int step = 0; step < limit -1; step++){
        for(int j = 0; j < limit - step-1 ; j++){
            if(data[j] > data[j+1]){
                swap(data[j], data[j+1]);
            }
        }
    }
}

double median(int data[], int limit){
    double total = 0;
    for(int i =0; i < limit; i++){
         total += data[i];
    }
    double mean = total/limit;
    return mean;
}
