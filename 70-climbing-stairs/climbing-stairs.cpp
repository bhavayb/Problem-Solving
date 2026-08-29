class Solution {
    int func(int n, vector<int>&dp){
        if(n <= 1) return 1;
        if(dp[n] != -1)return dp[n];
        int onestep = func(n-1, dp);
        int twostep = func(n-2, dp);
        return dp[n] = onestep + twostep;
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, -1);
        return func(n, dp);
    }
};