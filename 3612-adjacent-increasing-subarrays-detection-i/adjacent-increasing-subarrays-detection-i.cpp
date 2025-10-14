class Solution {
    bool isInc(int i , int j, vector<int>& nums){
        while(i < j){
            if(nums[i] >= nums[i+1]){
                return false;
            }
            i++;
        }
        return true;
    }
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int i = 0, j = i+k-1;
        if(nums.size() < 2*k) return false;
        while(j+k < nums.size()){
            if(isInc(i,j, nums) && isInc(j+1, j+k, nums)){
                return true;
            }
            i++; j++;
        }
        return false;
    }
};