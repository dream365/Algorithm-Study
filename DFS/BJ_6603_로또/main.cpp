#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX 6

int k;
bool* visit;
vector<int> num;
vector<int> ans;


void print(int* temp, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", *(temp + i));
    }
    printf("\n");
}

void DFS(int start, int item) {
    if(item == MAX) {
        int* temp = new int[item];

        for(int i = 0; i < item; i++)
            temp[i] = ans[i];

        sort(temp, temp + item);

        print(temp, item);

        return;
    }

    for(int i = start; i < k; i++) {
        if(!visit[i]) {
            ans.push_back(num[i]);
            visit[i] = true;

            DFS(i + 1, item + 1);

            ans.pop_back();
            visit[i] = false;
        }
    }
}

int main() {

    while (true) {
        scanf("%d", &k);

        if(k == 0)
            break;

        visit = new bool[k];

        for(int i = 0; i < k; i++)
            visit[k] = false;

        for(int i = 0; i < k; i++){
            int input;
            scanf("%d", &input);
            num.push_back(input);
        }

        DFS(0, 0);

        printf("\n");

        num.clear();
        ans.clear();

        delete visit;
    }
}