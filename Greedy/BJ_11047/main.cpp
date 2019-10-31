#include <stdio.h>
#include <vector>

using namespace std;

int getCurrencyNum(vector<int> &currencies, int totalPrice) {
    int currencyNum = 0;
    int currencySize = currencies.size();
    int curPrice = 0;

    while(curPrice != totalPrice) {
        for (int i = currencySize - 1; 0 <= i; i--) {
            int remainPrice = totalPrice - curPrice;
            if (currencies[i] <= remainPrice) {
                currencyNum++;
                curPrice += currencies[i];
                break;
            }
        }
    }

    return currencyNum;
}

int main() {
    int N, K;

    scanf("%d %d", &N, &K);

    vector<int> currencies(N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &currencies[i]);
    }

    printf("%d", getCurrencyNum(currencies, K));
    return 0;
}