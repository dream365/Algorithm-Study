#include <stdio.h>

long long zero[91];
long long one[91];

int main() {
    int num;
    scanf("%d", &num);

    for(int i = 1; i <= num; i++) {
        if(i == 1) {
            zero[i] = 0;
            one[i] = 1;
        } else {
            zero[i] = zero[i - 1] + one[i - 1];
            one[i] = zero[i - 1];
        }
    }

    printf("%lld", zero[num] + one[num]);
}