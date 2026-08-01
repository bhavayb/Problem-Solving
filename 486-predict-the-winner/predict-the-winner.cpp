class Solution {
    bool func(int i, int j, int sum1, int sum2, vector<int>& nums, bool flag){
        if(i > j){
            if(sum1 >= sum2) return true;
            else return false;
        }
        if(flag == true){
            return func(i+1, j, sum1 + nums[i], sum2,nums,  false) || func(i, j-1, sum1+ nums[j], sum2,nums, false);
        }
        return func(i+1, j, sum1, sum2 + nums[i] ,nums, true) && func(i, j-1, sum1, sum2 + nums[j],nums, true);
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        return func(0, nums.size()-1, 0, 0, nums, true);
    }
};