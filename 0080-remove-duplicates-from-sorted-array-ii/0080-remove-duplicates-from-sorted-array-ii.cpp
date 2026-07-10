class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mpp;
        for(auto it: nums){
            mpp[it]++;
        }
        int cnt=  0;
        int i = 0;
        for(auto it: mpp ){
            if(it.second == 1){
                cnt++;
                nums[i] = it.first;
                i++;
            }else{
                cnt = cnt+2;
                nums[i] = it.first;
                i++;
                nums[i] = it.first;
                i++;
            }
        }
        return cnt;
    }
};