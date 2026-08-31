class Solution {
    int func(int ind, int target, vector<int>& arr){
        if (ind == 0) {
            if (target == 0 && arr[0] == 0) return 2; 
            if (target == 0 || target == arr[0]) return 1; 
            return 0;
        }

        int nottake = func(ind-1, target, arr);
        int take = 0;
        if(arr[ind] <= target){
            take = func(ind-1, target - arr[ind], arr);
        }
        return take + nottake;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum =0;
        for(auto num: nums) sum += num;
        if (abs(target) > sum) return 0;
        if ((target + sum) % 2 != 0) return 0;
        int t= (target+sum)/2;
        return func(n-1, t, nums);
    }
};