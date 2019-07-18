#include <stdio.h>
#include <vector>
using namespace std;

int N;
vector<int> ans;
bool visit[9] = {false, };

void DFS(int len) {
    if(len == N) {
        for(int i = 0; i < ans.size(); i++)
            printf("%d ", ans[i]);
        printf("\n");

        return;
    }

    for(int i = 1; i <= N; i++) {
        if(!visit[i]) {
            visit[i] = true;
            ans.push_back(i);
            DFS(len + 1);
            ans.pop_back();
            visit[i] = false;
        }
    }
}

int main() {
    scanf("%d", &N);

    DFS(0);
}