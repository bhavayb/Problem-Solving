class Solution {
    int helper(int i, vector<int>& nums, vector<int>& dp) {
        int n = nums.size();

        if(i >= n - 1)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ans = 1e9;

        for(int j = 1; j <= nums[i] && i + j < n; j++) {
            ans = min(ans, 1 + helper(i + j, nums, dp));
        }

        return dp[i] = ans;
    }

public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return helper(0, nums, dp);
    }
};