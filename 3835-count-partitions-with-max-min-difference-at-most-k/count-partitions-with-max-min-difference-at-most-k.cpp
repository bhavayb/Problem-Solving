class Solution {
public:
    static const int MOD = 1'000'000'007;

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n + 2, 0), pref(n + 3, 0);

        dp[n] = 1;
        pref[n] = 1; 
        pref[n + 1] = 0;

        deque<int> minQ, maxQ;
        int j = n - 1;

        for (int i = n - 1; i >= 0; --i) {
            while (!minQ.empty() && minQ.back() > nums[i])
                minQ.pop_back();
            minQ.push_back(nums[i]);
            while (!maxQ.empty() && maxQ.back() < nums[i])
                maxQ.pop_back();
            maxQ.push_back(nums[i]);
            while (!minQ.empty() && !maxQ.empty() &&
                   (long long)maxQ.front() - minQ.front() > k) 
            {
                if (nums[j] == minQ.front()) minQ.pop_front();
                if (nums[j] == maxQ.front()) maxQ.pop_front();
                j--;
            }
            long long sum = (pref[i + 1] - pref[j + 2]) % MOD;
            if (sum < 0) sum += MOD;

            dp[i] = sum;
            pref[i] = (dp[i] + pref[i + 1]) % MOD;
        }

        return dp[0];
    }
};