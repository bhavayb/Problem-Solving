class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        int j = n-1;
        while(i <= j){
            while(j>= 0 && nums[j] == val) j--;
            if(i > j) break;
            if(nums[i] == val){
                swap(nums[i], nums[j]);
                j--;
            }

            i++;
        }
        return j+1;
    }
};