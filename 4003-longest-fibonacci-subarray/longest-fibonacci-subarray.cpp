class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = 2;
        vector<int> prefixSum;
        for(int i = 2; i<nums.size(); i++){
            prefixSum.push_back(nums[i-2] + nums[i-1]);
        }
        int i = 0, j = i+2;        
        int k = 0;
        while(j < nums.size() && k < prefixSum.size()){
            if(nums[j] != prefixSum[k]){
                k++; j++; i = j-2;
            }else{
                maxi = max(maxi, j-i+1);
                j++; k++;
            }
        }
        return maxi;
    }
};