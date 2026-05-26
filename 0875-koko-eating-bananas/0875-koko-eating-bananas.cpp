class Solution {
    private:
    long long func(vector<int>& nums, int k){
        long long sum = 0;
        for(auto num : nums){
            sum += ceil((double)num/(double)k);
        }
        return sum;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low =1;
        int high = piles[0];
        for(int i = 0; i < piles.size(); i++){
            if(piles[i] > high){
                high = piles[i];
            }
        }
        int ans=  -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(func(piles, mid) <= h){
                ans = mid;
                high = mid -1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};