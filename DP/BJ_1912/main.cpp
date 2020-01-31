#include<stdio.h>
#include<cstring>
#include<algorithm>
#define MIN -2000
using namespace std;

int N;
int num[100001];
int dp[100001];

int main() {

	int ans = MIN;
	scanf("%d", &N);

	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	dp[0] = num[0];
	ans = dp[0];

	for (int i = 1; i < N; i++) {
		dp[i] = max(dp[i - 1] + num[i], num[i]);
		ans = max(ans, dp[i]);
	}

	printf("%d", ans);

	return 0;
}
