class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0; int j = 1;
        int n = nums.size();
        while(j < n){
            if(nums[i] != nums[j]){
                swap(nums[i+1], nums[j]);
                i++; j++;
            }else{
                if(i > 0 && nums[i-1] == nums[i]){
                    j++;
                }else{
                    swap(nums[i+1], nums[j]);
                    i++; j++;
                }
            }
        }
        return i+1;
    }
};