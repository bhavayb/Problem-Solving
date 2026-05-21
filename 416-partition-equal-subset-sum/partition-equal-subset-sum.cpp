class Solution {
    bool func(int ind, int target, vector<int>& nums,vector<vector<int>>& dp ){
        if(target == 0) return true;
        if(ind == 0) return (target == nums[0]);

        if(dp[ind][target] != -1) return dp[ind][target];

        bool nottake = func(ind-1, target, nums, dp);
        bool take = false;
        if(target >= nums[ind]) take = func(ind-1, target - nums[ind], nums, dp);

        return dp[ind][target] = take || nottake;
    }
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num : nums){
            sum += num;
        }
        if(sum%2 != 0) return false;

        int target= sum/2;
        vector<vector<int>>dp(nums.size(), vector<int>(target+1, -1));
        return func(nums.size()-1, target, nums, dp);
    }
};