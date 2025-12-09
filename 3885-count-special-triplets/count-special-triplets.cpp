class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        long long MOD = 1'000'000'007;

        unordered_map<long long, long long> mpp1, mpp2;
        long long sum = 0;
        for (long long x : nums) {
            mpp1[x]++;
        }

        for (int i = 0; i < nums.size(); i++) {

            long long val = nums[i];
            long long need = 2LL * val;

            mpp1[val]--;
            long long leftCount = 0;
            auto itLeft = mpp2.find(need);
            if (itLeft != mpp2.end()) {
                leftCount = itLeft->second;
            }
            long long rightCount = 0;
            auto itRight = mpp1.find(need);
            if (itRight != mpp1.end()) {
                rightCount = itRight->second;
            }

            sum = (sum + leftCount * rightCount) % MOD;
            mpp2[val]++;
        }

        return sum;
    }
};
