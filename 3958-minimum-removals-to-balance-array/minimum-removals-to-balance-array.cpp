class Solution {
    // int ans = -1;
    // void func(int i, int j, vector<int>& nums, int k){
    //     if(nums[i]*k >= nums[j]){
    //         ans = max(ans, j-i+1);
    //     }
    //     if(i < j){
    //         func(i+1, j, nums, k);
    //         func(i, j-1, nums, k);
    //     }
    //     return ;
    // }
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = n;
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (j < n && nums[j] <= 1LL * nums[i] * k) {
                j++;
            }
            ans = min(ans, n - (j - i));
        }
        return ans;
    }
};