class Solution {
    int help(vector<int>& coins, int i, int amt,vector<vector<int>>& dp){
        if(amt == 0) return 0;
        if(i < 0 || amt < 0) return INT_MAX;

        if(dp[i][amt] != -1) return dp[i][amt];

        int notTake = help(coins, i-1, amt, dp);

        int take = help(coins, i, amt - coins[i] , dp);
        if(take != INT_MAX) take += 1;

        return dp[i][amt] = min(take, notTake);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
        int n = coins.size();
        int ans = help(coins, n-1, amount ,dp);
        if(ans == INT_MAX) return -1;
        return ans;
        // if(val == false) return -1;
        // sort(ans.begin(), ans.end());
        // return ans[0];
    }
};