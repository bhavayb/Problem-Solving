class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long cur_sum = 0;
        long long best_sum = -1e15;
        for (int i = 1, peak = -1; i + 1 < nums.size(); ++i) {
            if (nums[i] == nums[i - 1]) {
                peak = -1;
                cur_sum = 0;
                continue;
            }
            if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1]) {
                peak = i;
                cur_sum = nums[i];
                continue;
            }
            cur_sum += nums[i];
            if (nums[i] < nums[i - 1] && nums[i] < nums[i + 1]) {
                // we have a valley;
                if (peak == -1) continue;
                long long mx = nums[peak - 1];
                long long cur = nums[peak - 1];
                for (int j = peak - 2; j >= 0; --j) {
                    if (nums[j + 1] <= nums[j]) break;
                    cur += nums[j];
                    mx = std::max(mx, cur);
                }
                cur_sum += mx;
                mx = nums[i + 1];
                cur = nums[i + 1];
                int j = i + 2;
                for (int j = i + 2; j < nums.size(); ++j) {
                    if (nums[j] <= nums[j - 1]) break;
                    cur += nums[j];
                    mx = std::max(mx, cur);
                }
                cur_sum += mx;
                best_sum = std::max(cur_sum, best_sum);
                peak = -1;
                cur_sum = 0;
            }
        }
        return best_sum;
    }
};