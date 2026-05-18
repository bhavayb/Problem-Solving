class Solution {
    // int helperFunc(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
    //     if(i ==0 && j== 0&& grid[i][j] == 0) return 1;
    //     if(i<0 || j<0 ||grid[i][j] == 1) return 0;
    //     if(dp[i][j]!= -1)return dp[i][j];

    //     int left = helperFunc(i-1,j,grid,dp);
    //     int up = helperFunc(i, j-1, grid, dp);
    //     return dp[i][j] = left + up;
    // }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));

        // return helperFunc(m-1,n-1, obstacleGrid, dp);

        if(grid[0][0] == 0) dp[0][0] = 1;
        else dp[0][0] = 0;

        for(int i = 0; i<m; i++){
            for(int j = 0; j < n; j++){
                if(i ==0 && j == 0) continue;
                int left =0, up = 0;
                if(i > 0 && grid[i][j] == 0) left = dp[i-1][j];
                if(j> 0 && grid[i][j] == 0) up = dp[i][j-1];

                dp[i][j] = left + up;
            }
        }

        return dp[m-1][n-1];
    }
};