class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int bitwiseOr = 0;
        for(int i = 0; i< nums.size(); i++){
            if(nums[i]%2 == 0) bitwiseOr |= nums[i];
        }
        return bitwiseOr;
    }
};