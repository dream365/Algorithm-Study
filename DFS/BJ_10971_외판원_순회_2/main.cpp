#include <stdio.h>
using namespace std;

int N, ans, start;
int W[11][11];
bool visit[11] = {false, };

void DFS(int cur, int len, int weight) {

    if(ans < weight) return;

    if(W[cur][start] != 0 && len == N) {
        int totalWeight = weight + W[cur][start];

        if(totalWeight < ans)
            ans = totalWeight;

        return;
    }

    for(int i = 1; i <= N; i++) {
        if(!visit[i] && W[cur][i] != 0 && i != start) {
            visit[i] = true;
            DFS(i, len + 1, weight + W[cur][i]);
            visit[i] = false;
        }
    }
}

int main() {
    scanf("%d", &N);
    ans = 0;

    for(int i = 1; i <= N; i++) for(int j = 1; j <= N; j++) scanf("%d", &W[i][j]), ans += W[i][j];

    for(int i = 1; i <= N; i++) {
        start = i;
        DFS(i, 1, 0);
    }

    printf("%d", ans);
}