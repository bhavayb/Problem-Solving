class Solution {
    int func(int ind, int prev, vector<int>& nums, int n, vector<vector<int>> &dp){
        if(ind == n-1){
            if(  prev == -1|| nums[ind] > nums[prev]){
                return 1;
            }else return 0;
        }
        if(dp[ind][prev+1] != -1) return dp[ind][prev+1];
        int nottake = func(ind+1, prev, nums, n, dp);
        int take = 0;
        if(prev == -1 || nums[ind] > nums[prev] ){
            take = func(ind+1, ind, nums, n, dp)+1;
        }
        return  dp[ind][prev+1] = max(take, nottake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return func(0, -1, nums, n, dp);
    }
};