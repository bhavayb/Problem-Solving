class Solution {
    int sumofdigits(int n){
        int sum = 0;
        while(n > 0){
            int rem = n%10;
            sum += rem;
            n /=10;
        }
        return sum;
    }
public:
    int minElement(vector<int>& nums) {
        for(int i = 0; i< nums.size(); i++){
            int val = sumofdigits(nums[i]);
            nums[i] = val;
        }
        int ans = INT_MAX;
        for(auto it : nums){
            if(it < ans) ans = it;
        }
        return ans;
    }
};