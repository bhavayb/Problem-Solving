class Solution {
private:
    const long long MOD = 1e9 + 7;

    long long func(int ind, string& s, vector<long long>& dp,
                   vector<int>& prev) {

        if (ind < 0)
            return 1;

        if (dp[ind] != -1)
            return dp[ind];

        long long ans = (2 * func(ind - 1, s, dp, prev)) % MOD;

        if (prev[ind] != -1) {
            ans = (ans - func(prev[ind] - 1, s, dp, prev) + MOD) % MOD;
        }

        return dp[ind] = ans;
    }

public:
    int distinctSubseqII(string s) {
        int n = s.size();

        vector<long long> dp(n, -1);
        vector<int> prev(n, -1);
        vector<int> last(26, -1);

        for (int i = 0; i < n; i++) {
            prev[i] = last[s[i] - 'a'];
            last[s[i] - 'a'] = i;
        }

        return (func(n - 1, s, dp, prev) - 1 + MOD) % MOD;
    }
};