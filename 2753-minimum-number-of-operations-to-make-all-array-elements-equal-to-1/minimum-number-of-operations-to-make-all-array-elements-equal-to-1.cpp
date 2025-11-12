class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int countone = 0;
        for (int x : nums) if (x == 1) countone++;
        if (countone) return n - countone;
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int g = nums[i];
            for (int j = i + 1; j < n; j++) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == INT_MAX ? -1 : ans + n - 2;
    }
};
