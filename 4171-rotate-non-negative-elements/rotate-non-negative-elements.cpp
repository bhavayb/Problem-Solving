class Solution {
    vector<int> rotatearray(vector<int>& nums, int k){
        int n = nums.size();
        if(n == 0) return {};
        int r = k%n;
        vector<int> ans;
        for(int i = r; i < nums.size(); i++){
            ans.push_back(nums[i]);
        }
        for(int i = 0; i < r; i++){
            ans.push_back(nums[i]);
        }
        return ans;
    }
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> nonneg, idx;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]>= 0) {
                nonneg.push_back(nums[i]);
                idx.push_back(i);
            }
        }
        vector<int> finalans;
        finalans = rotatearray(nonneg, k);
        for(int i = 0; i < idx.size(); i++){
            nums[idx[i]] = finalans[i];
        }
        return nums;
    }
};