#include<stdio.h>
#include<cstring>
#include<algorithm>
#define MAX 90001
using namespace std;

int N, M;
int dp[301][301];

int solve(int n, int m) {
	if (n == 1 && m == 1) return 0;

	int& ret = dp[n][m];
	if (ret != -1) return ret;

	int nMid = n / 2;
	int mMid = m / 2;

	ret = MAX;

	for (int i = 1; i <= nMid; i++) {
		ret = min(ret, 1 + solve(i, m) + solve(n - i, m));
	}

	for (int i = 1; i <= mMid; i++) {
		ret = min(ret, 1 + solve(n, i) + solve(n, m - i));
	}
	
	dp[m][n] = ret;

	return ret;
}

int main() {

	scanf("%d %d", &N, &M);

	memset(dp, -1, sizeof(dp));

	printf("%d", solve(N, M));

	return 0;
}
