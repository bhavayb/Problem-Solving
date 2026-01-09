class Solution {
    bool func(string& p, string& s, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 && j < 0)
            return true;
        if (i < 0 && j >= 0)
            return false;
        if (j < 0 && i >= 0) {
            for (int x = 0; x <= i; x++) {
                if (p[x] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        if (p[i] == s[j] || p[i] == '?')
            return dp[i][j] = func(p, s, i - 1, j - 1, dp);
        if (p[i] == '*')
            return dp[i][j] =
                       func(p, s, i - 1, j, dp) || func(p, s, i, j - 1, dp);

        return dp[i][j] = false;
    }

public:
    bool isMatch(string s, string p) {
        int n = p.size(), m = s.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return func(p, s, n - 1, m - 1, dp);
    }
};
