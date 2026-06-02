class Solution {
    int func(vector<int>& nums, int goal){
        if(goal < 0 ) return 0;
        int n = nums.size();
        int l = 0, r = 0, sum = 0, cnt = 0;
        while(r < n){
            sum += (nums[r] % 2);
            while(sum > goal){
                sum  = sum - (nums[l] % 2);
                l++;
            };
            cnt = cnt + (r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int x = func(nums, k);
        int y = func(nums, k-1);
        return x - y;
    }
};