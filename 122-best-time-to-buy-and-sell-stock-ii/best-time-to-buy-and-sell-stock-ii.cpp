class Solution {
    int func(int ind, int buy, vector<int>&arr, vector<vector<int>>& dp ){
        if(ind == arr.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        if(buy){
            profit = max(-arr[ind] + func(ind+1, 0, arr,dp), 0 + func(ind+1, 1, arr, dp) );
        }else{
            profit = max(arr[ind] + func(ind+1, 1, arr, dp), 0 + func(ind+1, 0, arr, dp));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return func(0, 1, prices, dp);
    }
};