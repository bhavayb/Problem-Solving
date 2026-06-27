class Solution {
public:
#define ll long long
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]]++;
        }
        int ans = 1;
        for(int i =0;i < nums.size(); i++){
            int x = nums[i];
            if(x == 1){
                if(mpp[x]%2!=0) ans = max(ans, mpp[x]);
                else ans = max(ans, mpp[x]-1);
            }else{
                int cnt = 0;
                if(mpp[x]>= 2){
                    ll curr = x;
                    while(curr <= INT_MAX && mpp.find((int)curr)!= mpp.end()){
                        if(mpp[(int)curr] == 1){
                            cnt++;
                            break;
                        }
                        cnt++;
                        if(curr>LLONG_MAX/curr) break;
                        curr*= curr;
                    }
                }
                ans = max(ans,cnt*2-1);
            }
        }
        return ans;
    }
    
};