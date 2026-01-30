class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        //bool flag = false;
        int ans = 0;
        for(int i = nums.size()-2; i >= 0; i-- ){
            if(nums[i] >= nums[i+1]){
                ans = i+1;
                break;
            }
        }
        return ans;
    }
};