#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

int maxProfit(vector<int>& prices) {
        int high = 0, low = prices[0], profit, lowIndex;
        
        for(int i = 0; i < prices.size(); i++){
            if(prices[i] < low){
                low = prices[i];
                lowIndex = i;
                if(lowIndex == prices.size() - 1){
                    return 0;
                }
            }
        }

        for(int i = lowIndex; i < prices.size(); i++){
            if(prices[i] > high){
                high = prices[i];
            }
        }

        profit = high - low;
        cout << high << endl << low<< endl; 
        
        return profit;
}

int main(){
    vector<int> vec = {7,1,5,3,6,4};
    cout << maxProfit(vec);
}