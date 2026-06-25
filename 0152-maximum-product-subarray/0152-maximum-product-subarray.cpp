class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi  = INT_MIN;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            int p = nums[i];
            for(int j = i + 1; j < n; j++){
                maxi  = max(maxi, p);
                p *= nums[j];
            }
            maxi =  max(maxi, p);
        }
        return maxi;
    }
};