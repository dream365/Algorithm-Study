class Solution {
    int dp[100001];
public:
    int maxSubArray(vector<int>& nums) {
        int ans = -10000;
        int N = nums.size();
        
	    memset(dp, -1, sizeof(dp));
        
	    dp[0] = nums[0];
	    ans = dp[0];

	    for (int i = 1; i < N; i++) {
	    	dp[i] = max(dp[i - 1] + nums[i], nums[i]);
	    	ans = max(ans, dp[i]);
	    }
        
        return ans;
    }
};
