class Solution {
    int func(int i, int j, int n, vector<vector<int>>& grid, vector<vector<int>>& dp){
        
        if(i == 0 ) return grid[0][j];
        int left = 1e9, right = 1e9;
        if(dp[i][j] != INT_MAX) return dp[i][j];
        if (j > 0){
            left = grid[i][j] + func(i-1, j-1, n, grid, dp);
        }
        if(j < n-1){
            right = grid[i][j] + func(i-1,j+1,n, grid, dp);
        }
        int up = grid[i][j] + func(i-1, j, n, grid, dp);

        return dp[i][j] = min(left, min(right, up));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        int m =matrix.size();
        int mini = INT_MAX;
        vector<vector<int>> dp(m, vector<int>(n,INT_MAX));

        for(int i = 0; i < n; i++){
            int val = func(m-1, i, n, matrix, dp);
            mini = min(mini, val);
        }

        return mini;
    }
};