class Solution {
    int func(int ind, int amt, vector<int> arr, vector<vector<int>>& dp){
        if(amt == 0) return 1;
        if(ind == 0){
            if(amt%arr[0] == 0){
                return 1;
            }
            return 0;
        }
        if(dp[ind][amt]!= -1)return dp[ind][amt];
        int nottake = func(ind-1, amt, arr, dp);
        int take = 0;
        if(arr[ind] <= amt) take = func(ind, amt - arr[ind], arr, dp);
        return dp[ind][amt] =  take + nottake;
    }
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return func(n-1, amount, coins, dp);
    }
};