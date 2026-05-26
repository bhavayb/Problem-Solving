class Solution {
    long long func(vector<int>& nums, int k){
        long long sum = 0;
        for(auto num : nums){
            sum += ceil((double)num/(double)k);
        }
        return sum;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1; int high = nums[0];
        for(int i = 1; i< nums.size(); i++){
            if(nums[i] > high){
                high  =nums[i];
            }
        }
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(func(nums, mid) > threshold) low  = mid +1;
            else {
                ans = mid;
                high = mid -1;
            }
        }
        return ans;
    }
};