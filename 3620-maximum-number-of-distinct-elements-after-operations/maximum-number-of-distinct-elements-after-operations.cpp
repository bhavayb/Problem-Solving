class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int count = 0;
        int prev = INT_MIN;
        for(int i =0; i<nums.size(); i++){
            int minval = nums[i]-k;
            if(prev < minval){
                prev = minval;
                count++;
            }else if(prev < nums[i]+k){
                prev=  prev+1;
                count++;
            }

        }
        return count;
    }
};