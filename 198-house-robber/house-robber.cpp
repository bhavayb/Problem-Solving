class Solution {
    int helperfunction(vector<int>& houses, int ind , vector<int>& dp){
        if(ind < 0){
            return 0;
        }
        if(ind == 0) return houses[ind];
        if(dp[ind] != -1) return dp[ind];
        int pick = houses[ind] + helperfunction(houses, ind - 2, dp);
        int notpick = 0 + helperfunction(houses, ind - 1, dp);
        return dp[ind] = max(pick, notpick);
    }
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        vector<int> dp(n, -1);
        if(n == 1) return nums[0];
        int i = n - 1;
        return helperfunction(nums, i, dp);
    }
};