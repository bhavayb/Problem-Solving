class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int l = 0; int r = 0;
        int maxlen = 0;
        unordered_map<int, int> mpp;
        while(r < nums.size()){
            mpp[nums[r]]++;
            if(mpp.size() > 2){
                mpp[nums[l]]--;
                if(mpp[nums[l]] == 0) mpp.erase(nums[l]);
                l++;
            }
            if(mpp.size() <= 2){
                int len = r - l +1;
                maxlen = max(maxlen, len);
            }
            r++;
        }
        return maxlen;
    }
};