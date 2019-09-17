#include <stdio.h>

int N[1001];

int main() {
    int num;

    scanf("%d", &num);

    for(int i = 1; i <= num; i++) {
        if(i == 1)
            N[i] = 1;
        else if(i == 2)
            N[i] = 3;
        else {
            N[i] = N[i-1] + 2 * N[i-2];
            N[i] %= 10007;
        }
    }

    printf("%d", N[num]);
}