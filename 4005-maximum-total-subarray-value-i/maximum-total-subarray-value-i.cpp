class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxi = nums[0];
        long long mini = INT_MAX;
        for(int i =0; i< nums.size(); i++ ){
            if(nums[i] > maxi ) maxi = nums[i];
            if(nums[i] < mini ) mini = nums[i];
        }
        return k*(maxi-mini);
    }
};