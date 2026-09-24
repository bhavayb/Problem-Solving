class Solution {

private:
    int sumofdigits(int num){
        if(num==0) return 0;
        return num%10 + sumofdigits(num/10);
    }
public:
    int smallestIndex(vector<int>& nums) {
        for(int i = 0; i< nums.size(); i++){
            if( i == sumofdigits(nums[i])) return i;
        }
        return -1;
    }
};