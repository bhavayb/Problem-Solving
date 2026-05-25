class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0; int high = nums.size()-1;
        if(nums.size() == 1) return nums[0];
        while(low <= high){
            int mid = (low+high)/2;
            bool flag1 = false; bool flag2 = false;
            if((mid > 0 && nums[mid-1] != nums[mid]) || mid <= 0) flag1 = true;
            if((mid < nums.size()-1 && nums[mid+1] != nums[mid]) || mid >= nums.size()-1  ) flag2 = true;
            if(flag1 == true && flag2 == true){
                return nums[mid];
            }
            if(mid > 0 && nums[mid-1] == nums[mid]){
                if((mid-low+1)%2 == 1) high = mid -2;
                else low = mid+1;
            }else if(mid < nums.size()-1 && nums[mid] == nums[mid+1] ){
                if((high - mid +1) %2 == 0) high = mid -1;
                else low = mid+2;
            }
        }
        return -1;
    }
};