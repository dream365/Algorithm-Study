#include <iostream>
#include <vector>
#include<math.h>
#include<algorithm>


using namespace std;

int integerBreak(int n);
int integerBreak2(int n);



int dp[1000] = { 0, };
int main() {
	int n;
	cin >> n;
	dp[1] = 1;
	//dp[2] = 1;
	//dp[3] = 2;
	//dp[4] = 4;
	//dp[5] = 6;
	//for (int i = 6; i <= n; i++) {
	//	dp[i] = dp[i - 3]*3;
	//}
	cout << integerBreak(n) << endl;
	cout << dp[n] << endl;
	cout << integerBreak2(n) << endl;


	return 0;
}

int integerBreak(int n) {
	if (n == 2)
		return 1;
	else if (n == 3)
		return 2;
	else if (n % 3 == 1)
		return 4* pow(3, (n/3-1));
	else if (n % 3 == 2)
		return 6 * pow(3,(n / 3 - 1));
	else if (n % 3 == 0)
		return 3 * pow(3, (n / 3 - 1));
}

int integerBreak2(int n) {
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			dp[i] = max(dp[i], max(dp[j],j) * (i - j));
		}
	}
	return dp[n];
}
