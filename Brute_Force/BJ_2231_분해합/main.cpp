#include <stdio.h>

int N;

int getGenNum(int min) {

    for(int i = min; i <= N; i++) {
        int digitSum = 0;
        int temp = i;

        //자리수의 합
        while(temp) {
            digitSum += temp % 10;
            temp /= 10;
        }

        if(i + digitSum == N)
            return i;
    }

    return 0;
}


int main() {
    int digit = 0;
    int minNum, temp;

    scanf("%d", &N);

    temp = N;

    while(temp) temp /= 10, digit++;
    //최소는 N - 자리수 * 3 최대는 N
    minNum = N - digit * 9;

    printf("%d", getGenNum(minNum));

    return 0;
}