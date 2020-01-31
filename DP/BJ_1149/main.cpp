#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<queue>

#define MAX 1001
#define NONE -1
#define R 0
#define G 1
#define B 2
using namespace std;

int N;
int cost[1001][3];
int dp[1001][3];

int solve(int idx, int color) {
	if (idx == N) return min(cost[idx][color], MAX);

	int& ret = dp[idx][color];
	if (ret != -1 && idx != 0) return ret;

	if (idx == 0) {
		ret = min(solve(idx + 1, R), solve(idx + 1, G));
		ret = min(ret, solve(idx + 1, B));
	} else {
		int firstColor, secondColor;

		if (color == R)
			firstColor = G, secondColor = B;
		else if(color == G)
			firstColor = R, secondColor = B;
		else
			firstColor = R, secondColor = G;

		ret = cost[idx][color] + min(solve(idx + 1, firstColor), solve(idx + 1, secondColor));
	}

	return ret;
}

int main() {

	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}

	memset(dp, -1, sizeof(dp));

	printf("%d", solve(0, NONE));

	return 0;
}
