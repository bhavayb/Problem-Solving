class Solution {
    int f(int ind, int buy, int cap, int n, vector<int>& arr, vector<vector<vector<int>>>& dp){
        if(ind == n){
            return 0;
        }
        if(cap == 0){
            return 0;
        }
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];

        if(buy == 1){
            return dp[ind][buy][cap] = max(-arr[ind] + f(ind+1, 0, cap, n, arr, dp), 0 + f(ind+1, 1, cap, n, arr, dp));
        }
        else{
            return dp[ind][buy][cap] = max(arr[ind]+ f(ind+1, 1, cap-1, n, arr, dp), 0 + f(ind+1, 0, cap, n, arr, dp));
        }
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return f(0, 1, k, n, prices, dp);
    }
};