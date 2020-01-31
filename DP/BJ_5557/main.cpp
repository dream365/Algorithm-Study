#include "stdio.h"
#include<cstring>
#define ll long long

int N;
int nums[101];
ll dp[21][101];

ll solve(int sum, int pos) {
	if (sum < 0 || 20 < sum) return 0;
	if (pos == N) {
		if (sum == nums[pos]) return 1;
		return 0;
	}

	ll& num = dp[sum][pos];
	if (num != -1) return num;

	return num = solve(sum + nums[pos], pos + 1) + solve(sum - nums[pos], pos + 1);
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d", &nums[i]);
	}

	memset(dp, -1, sizeof(dp));

	printf("%lld", solve(nums[1], 2));

	return 0;
}
