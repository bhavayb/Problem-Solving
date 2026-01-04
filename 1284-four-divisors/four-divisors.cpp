class Solution {
    long long func(int n) {
        int cnt = 0;
        long long sum = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                cnt++;
                sum += i;

                if (i != n / i) {
                    cnt++;
                    sum += n / i;
                }
            }
            if (cnt > 4) return 0; // early stop
        }

        return (cnt == 4) ? sum : 0;
    }

public:
    int sumFourDivisors(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (int x : nums) {
            mpp[x]++;
        }

        long long ans = 0;
        for (auto &it : mpp) {
            ans += it.second * func(it.first);
        }
        return ans;
    }
};
