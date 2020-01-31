class Solution {
private:
    const int low = 1000;
    int dp[21][2001];    
public:
    int solve(vector<int>& nums, int pos, int sum, int S, int size) {
        if(pos == size) {
            if(sum - low == S)
                return 1;
            return 0;
        }
        
        int& ret = dp[pos][sum];
        if(ret != -1) return ret;
        
        return ret = solve(nums, pos + 1, sum + nums[pos], S, size) + solve(nums, pos + 1, sum - nums[pos], S, size);
    }
        
    int findTargetSumWays(vector<int>& nums, int S) {
        int size = nums.size();
        
        memset(dp, -1, sizeof(dp));
        
        return solve(nums, 1, low + nums[0], S, size) + solve(nums, 1, low + nums[0] * -1, S, size);
    }
};
