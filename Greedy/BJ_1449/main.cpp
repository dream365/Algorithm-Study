#include <stdio.h>
#include <algorithm>
using namespace std;

int main() {
    int N, L;
    int totalTapes = 0;

    scanf("%d %d", &N, &L);

    int* cracks = new int[N];

    for(int i = 0; i < N; i++) {
        scanf("%d", &cracks[i]);
    }

    sort(cracks, cracks + N);

    for(int i = 0; i < N; i++) {
        if(i == N - 1) {
            totalTapes++;
        } else {
            for(int j = i + 1; j < N; j++) {
                int diff = cracks[j] - cracks[i] + 1;
                if(L < diff) {
                    i = j - 1;
                    totalTapes++;
                    break;
                } else if(L == diff) {
                    i = j;
                    totalTapes++;
                    break;
                }
            }
        }
    }

    printf("%d", totalTapes);
}