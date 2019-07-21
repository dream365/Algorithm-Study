#include <stdio.h>
using namespace std;

int board[128][128];
int white, blue;

void solve(int sy, int sx, int ey, int ex) {

    if(sy == ey && sx == ex) {
        board[sy][sx] ? blue++ : white++;
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
        firstBlockColor ? blue++ : white++;
        return;
    }

    solve(sy, sx, (ey + sy) / 2, (ex + sx) / 2);
    solve(sy, (ex + sx) / 2 + 1, (ey + sy) / 2, ex);
    solve((ey + sy) / 2 + 1, sx, ey, (ex + sx) / 2);
    solve((ey + sy) / 2 + 1, (ex + sx) / 2 + 1, ey, ex);
}


int main() {
    int N;

    white = 0, blue = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }

    solve(0, 0, N - 1, N - 1);

    printf("%d\n", white);
    printf("%d\n", blue);
}