#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

//prototypes
int *makeArr(int);
void getData(int*, int);
void selectionSort(int*, int);
int median(int*, int);
double average(int*, int);
int mode (int *, int);

int main(){
    int students = 0; // to store the number of students
    int *stats; //pointer to the array of statistics


    cout << "How many students were surveyed? ";
    cin >> students;
    //checks to make sure input is valid
    while (students < 0){
            cout << "input is invalid please enter a new value: ";
            cin >> students;
        }
    stats = makeArr(students);

    getData(stats, students);
    selectionSort(stats, students);
    cout << "\n\nThe median of the group is: " << median(stats, students);
    cout << "\nThe average number of movies watched is: " << setprecision(3) << average(stats, students);
    cout << "\nThe mode of the movies watched is: " << mode(stats, students);


    delete stats; //deallocating the pointer to the array
    return 0;
}

int *makeArr(int students){
    int *stats = new int[students]; //points to an array to be returned
    return stats;
}

void getData(int* stats, int size){
    //puts values into the array
    for(int i = 0; i < size; i++){
        cout << "\nHow many movies did student " << i+1 << " see? ";
        cin >> *(stats + i);
        //checking if input is valid
        while ( *(stats +i) < 0){
            cout << "input is invalid please enter a new value: ";
            cin >> *(stats + i);
        }
    }
}


//Sorts the data via selection sort
void selectionSort(int* stats, int size){
    int startScan, minIndex, minValue;
    for(startScan = 0; startScan < (size - 1); startScan++){
        minIndex = startScan;
        minValue = *(stats + startScan); //aka minValue = stats[startScan]
        for(int index = startScan + 1; index < size; index++){
            if (*(stats + index) < minValue){
                minValue = *(stats + index);
                minIndex = index;
            }
        }
        *(stats + minIndex) = *(stats + startScan);
        *(stats + startScan) = minValue;
    }
}


//finds the middle value of the data after determining whether the size is even or odd
int median(int* stats, int size){
    if(size%2 == 1){ //determines if array size is odd
        int midIndex = (size/2);//gets the middle index of the odd array 
        return *(stats + midIndex);//aka return stats[(size/2)]
    }
    else{ //its even otherwise
        int midIndex = (size/2);
        int mid = *(stats + midIndex) + *(stats + midIndex -1);// adds the 2 middle values together
        return mid;
    }
}


//gets the average of the array
double average(int *stats, int size){
    double total = 0;
    for (int i = 0; i < size; i++){
        total += *(stats + i);
    }

    return total/size;
}

int mode (int *stats, int size){
    int count = -1, maxCount = 0, maxVal = -1;
    //Goes through the array i^2 amount of times to compare each value to see if there are any matches
    for(int i = 0; i < size; i++){
        count = 0;
        for(int j = 0; j < size; j++){
            if (*(stats + i) == *(stats + j)){ //If a match is found, count will go up by 1
                count ++;
            }
        }
        if(count > maxCount){ //If the current number being checked has more counts than the current max, that number will be set as the max value
            maxCount = count;
            maxVal = *(stats + i);
        }
        else if(maxCount == 1){ //If there is only one number in the list, maxValue is set to indicate no matches are present
            maxVal = -1;
        }
    }
    return maxVal;
}




