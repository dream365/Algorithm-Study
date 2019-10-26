#include <stdio.h>
#define MAX 91

struct GcdPair {
    long long A;
    long long B;
}gcdPairs[MAX];

void setGcdPairs() {
    for(int i = 2; i <= 90; i++) {
        gcdPairs[i].B = gcdPairs[i-1].A;
        gcdPairs[i].A = gcdPairs[i-1].A + gcdPairs[i-2].A;
    }
}

int main() {
    gcdPairs[0].A = 1;
    gcdPairs[0].B = 0;
    gcdPairs[1].A = 2;
    gcdPairs[1].B = 1;

    setGcdPairs();

    int T;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++) {
        int K;
        scanf("%d", &K);
        printf("#%d %lld %lld\n", i, gcdPairs[K].A, gcdPairs[K].B);
    }
}