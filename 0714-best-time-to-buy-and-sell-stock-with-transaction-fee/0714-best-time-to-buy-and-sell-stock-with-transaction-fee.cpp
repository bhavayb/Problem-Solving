class Solution {
    int func(int ind, int buy, vector<int>&arr, vector<vector<int>>& dp , int fee){
        if(ind == arr.size()) return 0;
        if(dp[ind][buy] != -1) return dp[ind][buy];
        int profit = 0;
        if(buy){
            profit = max(-arr[ind] + func(ind+1, 0, arr,dp, fee), 0 + func(ind+1, 1, arr, dp, fee) );
        }else{
            profit = max(arr[ind] - fee + func(ind+1, 1, arr, dp, fee), 0 + func(ind+1, 0, arr, dp, fee));
        }
        return dp[ind][buy] = profit;
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2,-1));
        return func(0, 1, prices, dp, fee);
    }
};