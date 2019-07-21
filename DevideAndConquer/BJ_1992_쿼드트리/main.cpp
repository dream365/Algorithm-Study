#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;

int board[64][64];
string ans;

void solve(int sy, int sx, int ey, int ex) {

    if(sy == ey && sx == ex) {
        board[sy][sx] ? ans += "1" : ans += "0";
        return;
    }

    bool allSameColor = true;
    int firstBlockColor = board[sy][sx];

    for(int i = sy; i <= ey; i++)
        for(int j = sx; j <= ex; j++)
            if(board[i][j] != firstBlockColor) {
                allSameColor = false;
                break;
            }

    if(allSameColor) {
        firstBlockColor ? ans += "1" : ans += "0";
        return;
    }

    ans += "(";

    solve(sy, sx, (ey + sy) / 2, (ex + sx) / 2);
    solve(sy, (ex + sx) / 2 + 1, (ey + sy) / 2, ex);
    solve((ey + sy) / 2 + 1, sx, ey, (ex + sx) / 2);
    solve((ey + sy) / 2 + 1, (ex + sx) / 2 + 1, ey, ex);

    ans += ")";
}


int main() {
    int N;

    ans = "";

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        char* charArr = new char[N];

        scanf("%s", charArr);

        for(int j = 0; j < N; j++) {
            board[i][j] = charArr[j] - '0';
        }

        delete charArr;
    }

    solve(0, 0, N - 1, N - 1);

    printf("%s\n", ans.c_str());
}