#include <stdio.h>
#include <vector>
using namespace std;

int C, N, M;
int ans = 0;
bool visit[11];
bool isFriend[11][11];

void init() {
    ans = 0;

    for(int i = 0; i < 11; i++) {
        visit[i] = false;
        for(int j = 0; j < 11; j++) {
            isFriend[i][j] = false;
        }
    }
}

void DFS(int idx, int len) {
    if(len == N) {
        ans++;
        return;
    }

    for(int i = 0; i < N; i++) {
        if(!visit[i] && !visit[idx] && isFriend[idx][i]) {
            int nextIdx;
            visit[i] = true;
            visit[idx] = true;

            for(int j = 0; j < N; j++)
                if(!visit[j]) {
                    nextIdx = j;
                    break;
                }

            DFS(nextIdx, len + 2);

            visit[i] = false;
            visit[idx] = false;
        }
    }
}

int main() {

    scanf("%d", &C);

    for(int i = 0; i < C; i++) {
        int first, second;

        scanf("%d %d", &N, &M);
        init();

        for(int j = 0; j < M; j++) {
            scanf("%d %d", &first, &second);

            isFriend[first][second] = true, isFriend[second][first] = true;
        }

        DFS(0, 0);

        printf("%d\n", ans);
    }
}