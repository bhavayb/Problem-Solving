class Solution {
    bool func(int i, int k,  vector<int>& nums, vector<vector<int>>& dp){
        if(k == 0) return true;
        if(i < 0 || k < 0) return false;
        if(dp[i][k] != -1) return dp[i][k];
        return dp[i][k] =  func(i-1, k-nums[i], nums, dp) || func(i-1, k, nums, dp);
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        if(sum % 2== 1) return false;
        vector<vector<int>> dp(nums.size(), vector<int>(sum/2 + 1, -1));
        
        return func(nums.size() -1, (sum/2), nums, dp);
    }
};