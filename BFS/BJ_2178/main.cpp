#include <stdio.h>
#include <queue>
#include <cstring>
using namespace std;

int N, M;
int graph[101][101];
int visit[101][101];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int BFS() {
    queue<pair<int, int>> q;
    int ans = 0;

    q.push(make_pair(1, 1));
    visit[1][1] = 1;
    ans++;

    while(!q.empty()) {
        pair<int, int> p = q.front();
        int depth = visit[p.first][p.second];
        q.pop();

        if(p.first == N && p.second == M)
            return visit[N][M];

        for(int i = 0; i < 4; i++) {
            int row = p.first + dir[i][0];
            int col = p.second + dir[i][1];

            if(0 < row && row <= N && 0 < col && col <= M && visit[row][col] == 0 && graph[row][col]) {
                q.push(make_pair(row, col));
                visit[row][col] = depth + 1;
            }
        }
    }

    return ans;
}

int main() {
    scanf("%d %d", &N, &M);
    memset(visit, 0, sizeof(visit));

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%1d", &graph[i][j]);
        }
    }

     printf("%d", BFS());

    return 0;
}