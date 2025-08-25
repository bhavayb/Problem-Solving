class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int count = 0;
        int maxCount = 0;
        int zero = 0;
        int i = 0, j = 0;
        while( i < nums.size() && j < nums.size()){
            
            if(nums[j] == 0) zero++;
            while(zero > 1 ){
                if(nums[i] == 0) zero--;
                i++;
            }
            count = j-i;
            maxCount = max(maxCount, count);
            j++;
        }
        return maxCount;
    }
};