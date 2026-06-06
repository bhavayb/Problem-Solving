class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> leftsum(n, 0), rightsum(n, 0);
        for(int i = 0; i < n; i++ ) {
            if( i == 0 ) leftsum[i] = 0;
            else leftsum[i] = leftsum[i-1] + nums[i-1];
        }
        for(int i = n-1; i >= 0; i-- ) {
            if( i == n-1 ) rightsum[i] = 0;
            else rightsum[i] = rightsum[i+1] + nums[i+1];
        }
        for(int i =0 ; i < n; i++){
            nums[i] = abs(leftsum[i] - rightsum[i]);
        }
        return nums;
    }
};