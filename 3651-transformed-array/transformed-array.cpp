class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result(nums.size());
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                int j = (i + nums[i])%n;
                result[i] = nums[j];
            }else if(nums[i] < 0){
                int j = abs(nums[i])%n;
                int k = (i + n - j)%n;
                result[i] = nums[k];
            }else{
                result[i] = nums[i];
            }
        }
        return result;
    }
};