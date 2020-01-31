#include<stdio.h>
#include<cstring>
#include<algorithm>
#define MIN -1
using namespace std;

int N;
int tri[501][501];
int dp[501][501];

int solve(int h, int pos) {
	if (h == N - 1) return max(tri[h][pos], MIN);

	int& ret = dp[h][pos];
	if (ret != -1) return ret;

	return ret = tri[h][pos] + max(solve(h + 1, pos), solve(h + 1, pos + 1));
}

int main() {

	scanf("%d", &N);

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i + 1; j++)
			scanf("%d", &tri[i][j]);
	}

	printf("%d", solve(0, 0));

	return 0;
}
