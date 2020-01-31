#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;

int N, K;
int depth[100001];

void BFS() {
	queue<int> q;
	q.push(N);
	depth[N] = 0;

	while (!q.empty()) {
		int cur = q.front();
		int curDepth = depth[cur];
		q.pop();

		if (cur == K) {
			printf("%d", curDepth);
		}

		for (int i = 0; i < 3; i++) {
			int next;
			if (i == 0)
				next = cur - 1;
			else if (i == 1)
				next = cur + 1;
			else if (i == 2)
				next = cur * 2;

			if (0 <= next && next <= 100000 && depth[next] == -1) {
				q.push(next);
				depth[next] = curDepth + 1;
			}
		}
	}
}

int main() {

	scanf("%d %d", &N, &K);

	memset(depth, -1, sizeof(depth));

	BFS();

	return 0;
}
