#include <stdio.h>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

bool graph[1001][1001];
bool visit[1001];
int N, M, V;

void DFS() {
    stack<int> s;
    priority_queue<int, vector<int>, less<int>> pq;
    s.push(V);

    while(!s.empty()) {
        int cur = s.top();
        s.pop();

        if(!visit[cur]) {
            printf("%d ", cur);
            visit[cur] = true;
        }

        for(int i = N; 1 <= i; i--) {
            if(!visit[i] && graph[cur][i]) {
                s.push(i);
            }
        }
    }

    printf("\n");
}

void BFS() {
    queue<int> pq;
    pq.push(V);

    while(!pq.empty()) {
        int cur = pq.front();
        pq.pop();

        if(!visit[cur]) {
            printf("%d ", cur);
            visit[cur] = true;
        }

        for(int i = 1; i <= N; i++) {
            if(!visit[i] && graph[cur][i]) {
                pq.push(i);
            }
        }
    }
}

int main() {
    memset(graph, false, sizeof(graph));
    memset(visit, false, sizeof(visit));

    scanf("%d %d %d", &N, &M, &V);

    for(int i = 0; i < M; i++) {
        int first, second;
        scanf("%d %d", &first, &second);
        graph[first][second] = true;
        graph[second][first] = true;
    }

    DFS();

    memset(visit, false, sizeof(visit));

    BFS();

    return 0;
}