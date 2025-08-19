class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long total = 0; 
        int i = 0, j = 0;
        int n = nums.size();

        while (j < n) {
            if (nums[j] != 0) {
                int len = j - i;   
                if (len > 0) {
                    total += 1LL * len * (len + 1) / 2;
                }
                i = j + 1;  
            }
            j++;
        }
        int len = j - i;
        if (len > 0) {
            total += 1LL * len * (len + 1) / 2;
        }

        return total;
    }
};