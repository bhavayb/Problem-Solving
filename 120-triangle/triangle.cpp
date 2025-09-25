class Solution {
private:
    vector<vector<int>> dp;

    long long minSum(vector<vector<int>>& triangle, int i, int row) {
        if (row == triangle.size() - 1) {
            return triangle[row][i];
        }

        if (dp[row][i] != INT_MAX)
            return dp[row][i];

        long long down = minSum(triangle, i, row + 1);
        long long right = minSum(triangle, i + 1, row + 1);

        return dp[row][i] = triangle[row][i] + min(down, right);
    }

public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        dp.assign(n, vector<int>(n, INT_MAX));
        return minSum(triangle, 0, 0);
    }
};
