class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int leftsum = 0;
        int rightsum = 0;
        for(int i = 0; i < nums.size(); i++){
            rightsum += nums[i];
        }
        int count = 0;
        for(int i = 0; i < nums.size()-1; i++){
            leftsum += nums[0];
            rightsum-= nums[0];
            if(abs(leftsum - rightsum)%2 == 0)count++;
        }
        return count;
    }
};