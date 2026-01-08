#include <iostream>
using namespace std;

void maxProfit(int* prices, int n) {
    int bestBuy = INT16_MAX, maxProfit = INT16_MIN;
    for(int i=0; i<n; i++) {
        bestBuy = min(bestBuy, prices[i]);
        maxProfit = max(maxProfit, prices[i] - bestBuy);
    }
    cout << "The max profit is: " << maxProfit << endl;
}

int main() {
    int prices[6] = {7, 1, 5, 3, 6, 2};
    int n = sizeof(prices)/sizeof(int);

    maxProfit(prices,n);


    return 0;
}