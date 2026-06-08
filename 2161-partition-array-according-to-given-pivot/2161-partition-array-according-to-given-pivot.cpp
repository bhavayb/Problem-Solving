class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans;
        //int less = 0; int high = 0; int equal = 0;
        // for(int i = 0; i < n; i++){
        //     if(nums[i] < pivot) less++;
        //     else if(nums[i] > pivot) high++;
        //     else equal++;
        // }
        // int i = 0; int j = less; int k = less + equal;
        for(int i  = 0; i < n; i++){
            if(nums[i] < pivot) ans.push_back(nums[i]);
        }
        for(int i  = 0; i < n; i++){
            if(nums[i] ==  pivot) ans.push_back(nums[i]);
        }
        for(int i  = 0; i < n; i++){
            if(nums[i] > pivot) ans.push_back(nums[i]);
        }
        
        return ans;
    }
};