class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        if(nums.size() % k != 0) return false;
        if(k == 1) return true;
        unordered_map<int, int> mpp;
        if(k == nums.size()){
            for(int i = 0; i< nums.size(); i++){
                mpp[nums[i]]++;
            }
            for(auto entity: mpp){
                if(entity.second>1) return false;
            }
            return true;
        }
        int grps = nums.size()/k;
        
        for(int i = 0; i< nums.size(); i++){
            mpp[nums[i]]++;
        }
        for(auto entity: mpp){
            if(entity.second > grps) return false;
        }
        return true;
    }
};