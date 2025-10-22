class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        bool zero = false; int count = 0; int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 0){
                zero = true;
                count++;
            }
        }
        if(count == nums.size()){
            return nums;
        }
        if(count > 1){
            for(int i =0; i< n; i++){
                nums[i] = 0;
            }
            return nums;
        }
        long long p = 1;
        if(zero == true){
            for(int i = 0; i< n; i++){
                if( nums[i]!= 0){
                    p*= nums[i];
                }
            }
            for(int i = 0; i< n; i++){
                if(nums[i] == 0){
                    nums[i] = p;
                }else{
                    nums[i] = 0;
                }
            }
            return nums;
        }

        long long product = 1;
        for(int i = 0; i< nums.size(); i++){
            product *= nums[i];
        }
        for(int i = 0; i< nums.size(); i++){
            nums[i] = product/nums[i];
        }
        return nums;

    }
};