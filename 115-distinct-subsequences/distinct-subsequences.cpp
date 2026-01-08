class Solution {
    int func(string s, string t, int i , int j, vector<vector<int>>& dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i] == t[j]){
            return dp[i][j] = func(s,t,i-1, j-1, dp) + func(s,t,i-1,j,dp);
        }
        return dp[i][j] = func(s,t,i-1,j,dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return func(s,t,n-1,m-1,dp);
        // for(int j = 1; j <= m; j++){
        //     dp[0][j] = 0;
        // }
        // for(int i = 1; i <= n; i++){
        //     dp[i][0] = 1;
        // }
        // for(int i = 1; i <= n; i++){
        //     for(int j = 1; j <= m; j++){

        //     }
        // }
    }
};