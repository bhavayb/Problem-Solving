class Solution {
    int func(vector<vector<int>>& matrix, int i, int j ,vector<vector<int>>& dp){
        
        if((i>0 && j< 0) || (i<0 && j>0))return 0;
        
        if(matrix[i][j] == 1) return 0;
        if(i==0 && j ==0) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = func(matrix, i-1, j, dp) + func(matrix, i,j-1, dp);
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(matrix, m-1, n-1, dp);
    }
};