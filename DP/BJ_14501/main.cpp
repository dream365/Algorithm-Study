#include<stdio.h>
#include<cstring>
#include<utility>
#include<algorithm>
using namespace std;

int N;
int T[16], P[16];
int dp[16];

int solve(int day) {
	if (N < day) return 0;

	int& ret = dp[day];
	if (ret != -1) return ret;
	
	return ret = max(solve(day + 1), (N + 1) < day + T[day] ? 0 : P[day] + solve(day + T[day]));
}

int main() {

	scanf("%d", &N);

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &T[i], &P[i]);
	}

	printf("%d", solve(1));

	return 0;
}
