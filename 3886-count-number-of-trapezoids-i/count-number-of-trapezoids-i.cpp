class Solution {
private:
    long long nCr2(long long n) {
        return n < 2 ? 0 : (n * (n - 1)) / 2;
    }

public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> freq;
        const long long mod = 1e9 + 7;

        for (auto &p : points) {
            freq[p[1]]++;
        }

        long long ans = 0, sum = 0;

        for (auto &it : freq) {
            long long edge = nCr2(it.second);

            ans = (ans + edge * sum) % mod;
            sum = (sum + edge) % mod;
        }

        return ans;
    }
};
