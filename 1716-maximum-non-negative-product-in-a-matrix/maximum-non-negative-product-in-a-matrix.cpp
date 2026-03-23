class Solution {
private:
    pair<long long, long long>
    func(int i, int j, vector<vector<int>>& grid,
         vector<vector<pair<long long, long long>>>& dp) {
        if (i < 0 || j < 0)
            return {LLONG_MIN, LLONG_MAX};
        if (i == 0 && j == 0)
            return {grid[0][0], grid[0][0]};
        if (dp[i][j].first != LLONG_MIN)
            return dp[i][j];

        auto up = func(i - 1, j, grid, dp);
        auto left = func(i, j - 1, grid, dp);

        long long mx = LLONG_MIN;
        long long mn = LLONG_MAX;

        if (up.first != LLONG_MIN) {
            long long a = up.first * grid[i][j];
            long long b = up.second * grid[i][j];
            mx = max({mx, a, b});
            mn = min({mn, a, b});
        }

        if (left.first != LLONG_MIN) {
            long long a = left.first * grid[i][j];
            long long b = left.second * grid[i][j];
            mx = max({mx, a, b});
            mn = min({mn, a, b});
        }

        return dp[i][j] = {mx, mn};
    }

public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<pair<long long, long long>>> dp(
            m, vector<pair<long long, long long>>(n, {LLONG_MIN, LLONG_MAX}));

        auto res = func(m - 1, n - 1, grid, dp);

        if (res.first < 0)
            return -1;
        return res.first % 1000000007;
    }
};