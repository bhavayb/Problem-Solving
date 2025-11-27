class Solution {
public:
    long long max(long long a, long long b) {
        if (a>b) return a;
        return b;
    }
    long long maxSubarraySum(vector<int>& nums, int k) {
        vector<long long> maxSums(k);
        long long curSum = 0;
        for (int i = 0; i<k; i++) {
            curSum += nums[i];
        }
        maxSums[k-1] = curSum;
        long long ans = curSum;

        for (int i = k; i<nums.size(); i++) {
            curSum += nums[i];
            curSum -= nums[i-k];
            maxSums[i%k] = max(maxSums[i%k], 0);
            maxSums[i%k] += curSum;
            ans = max(ans, maxSums[i%k]);
        }

        return ans;
    }
};