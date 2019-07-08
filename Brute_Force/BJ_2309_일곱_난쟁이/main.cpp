#include <stdio.h>
#include <vector>
#include <algorithm>

#define MAX 10

using namespace std;

int H[MAX];
bool visit[MAX] = {false, };

vector<int> num;
vector<int> ans;

void DFS(int cur, int cnt) {

    if(cnt == 7) {
        int sum = 0;
        for(int i = 0; i < num.size(); i++) {
            sum += H[num[i]];
        }

        if(sum == 100 && ans.empty()) {

            for(int i = 0; i < num.size(); i++) {
                ans.push_back(H[num[i]]);
            }

            return;
        }

    }

    for(int i = cur; i < 9; i++) {
        if(!visit[i]) {
            num.push_back(i);
            visit[i] = true;

            DFS(cur, cnt + 1);

            visit[i] = false;
            num.pop_back();
        }
    }

}

int main() {

    for(int i = 0; i < 9; i++) {
        scanf("%d", &H[i]);
    }

    sort(H, H + 9);

    DFS(0, 0);

    for(int i = 0; i < ans.size(); i++)
        printf("%d\n", ans[i]);
}