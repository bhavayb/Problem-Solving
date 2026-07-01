class Solution {
    bool helper(int i, vector<int>& nums, int n, vector<int>& dp){
        if(i == n-1) return true;
        if(i > n-1) return false;
        if(nums[i] == 0) return false;
        if(dp[i] != -1) return dp[i];
        bool flag=  false;
        for(int j = 1; j <= nums[i]; j++){
            flag = flag || helper(i+j, nums, n, dp);
            if(flag) return dp[i] = true;
        }
        return dp[i] = flag;
    }
public:
    bool canJump(vector<int>& nums) {
        //if(nums[0] == 0) return false;
        int n=  nums.size();
        vector<int> dp(n, -1);
        return helper(0, nums, n, dp);
    }
};