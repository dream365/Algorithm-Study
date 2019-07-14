#include <stdio.h>

using namespace std;

int N, ans;
char board[51][51];

void swap(char& num1, char& num2) {
    char temp = num2;
    num2 = num1;
    num1 = temp;
}

void countMax() {
    char curChar;
    int cnt = 0;

    for(int x = 0; x <= N - 1; x++) {
        curChar = board[0][x];
        cnt = 0;

        for(int y = 0; y <= N - 1; y++) {
            if(board[y][x] == curChar)
                cnt++;
            else {
                curChar = board[y][x];
                cnt = 1;
            }

            if(ans < cnt)
                ans = cnt;
        }
    }

    cnt = 0;

    for(int y = 0; y <= N - 1; y++) {
        curChar = board[y][0];
        cnt = 0;

        for(int x = 0; x <= N - 1; x++) {
            if(board[y][x] == curChar)
                cnt++;
            else {
                curChar = board[y][x];
                cnt = 1;
            }

            if(ans < cnt)
                ans = cnt;
        }
    }
}

void swapAndCount() {
    for(int py = 0; py < N - 1; py++) {
        for(int px = 0; px <= N - 1; px++) {
            swap(board[py][px], board[py + 1][px]);

            countMax();

            swap(board[py][px], board[py + 1][px]);
        }
    }

    for(int py = 0; py <= N - 1; py++) {
        for(int px = 0; px < N - 1; px++) {
            swap(board[py][px], board[py][px + 1]);

            countMax();

            swap(board[py][px], board[py][px + 1]);
        }
    }
}

int main() {
    scanf("%d", &N);

    ans = 1;

    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            scanf(" %C", &board[i][j]);

    swapAndCount();

    printf("%d", ans);

    return 0;
}