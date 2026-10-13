class Solution {
    typedef long long ll;
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i< n; i++){
            if(nums[i] < 0) nums[i] = -nums[i];
        }
        sort(nums.begin(), nums.end());
        
        int i = n/2;
        // if(n%2 == 0){
        //     i = n/2;
        // }else{
        //     i = n/2+1;
        // }
        ll sum = 0, diff = 0;
        for(int j = 0; j < i; j++){
            diff +=(ll) nums[j]*nums[j];
        }
        for(int j = i;j < n; j++){
            sum += (ll)nums[j]*nums[j];
        }
        return (sum - diff);
    }
};