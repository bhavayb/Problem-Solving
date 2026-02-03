class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int p=-1,q=-1,n=nums.size();
        if(n<3){
            return false;
        }
        for(int i=1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                p=i-1;
                break;
            }
        }
        if (p <= 0 || p >= n-1) return false;
        for(int i=p+1;i<n;i++){
            if(nums[i-1]<=nums[i]){
                q=i-1;
                break;
            }
        }
        if (q <= p || q >= n-1) return false;
        for(int i=q+1;i<n;i++){
            if(nums[i]<=nums[i-1]){
                return false;
            }
        }
        return true;;
    }
};