class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(auto& num: nums){
            if(num < 0) num = -(num);
        }
        sort(nums.begin(), nums.end());
        long long firstHalf = 0;
        long long secondHalf = 0;
        for(int i = 0; i < nums.size()/2; i++){
            firstHalf += nums[i]*nums[i];
        }
        for(int i = nums.size()/2; i < nums.size(); i++ ){
            secondHalf += nums[i]*nums[i];
        }
        return secondHalf - firstHalf;
    }
};