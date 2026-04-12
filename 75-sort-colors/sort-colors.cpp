class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0; int one = 0; int two = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0) zero++;
            else if(nums[i] == 1) one++;
            else two++;
        }

        int i = 0, j = zero, k = zero+one;
        while(i < zero || j < zero+one || k < zero + one + two){
            if(i < zero){
                nums[i] = 0; 
                i++;
            }
            if(j < zero+ one){
                nums[j] = 1;
                j++;
            }
            if(k < zero + one + two) {
                nums[k] = 2;
                k++;
            }
        }
    }
};