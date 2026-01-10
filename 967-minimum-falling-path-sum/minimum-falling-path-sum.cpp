class Solution {
    // int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp ){
    //     if(j < 0 || j >= matrix[0].size()) return 1e9;
    //     if(i == 0) return matrix[0][j];
    //     if(dp[i][j] != -1) return dp[i][j];
    //     return dp[i][j] = matrix[i][j] + min(func(i-1, j, matrix, dp), min(func(i-1, j-1, matrix, dp), func(i-1,j+1, matrix, dp)));

    // }
    //int helper()
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(); int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int j = 0; j < n; j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i = 1; i< m; i++){
            for(int j = 0; j < n; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int uleft = matrix[i][j];
                if(j-1 >= 0) uleft += dp[i-1][j-1];
                else uleft = 1e9;
                int uright = matrix[i][j];
                if(j+1 < n) uright += dp[i-1][j+1];
                else uright = 1e9;
                dp[i][j] = min(up, min(uright, uleft));
            }
        }
        


        int ans= INT_MAX;
        for(int j = 0; j < n; j++){
            ans = min(ans , dp[m-1][j]);
        }
        return ans;
    }
};