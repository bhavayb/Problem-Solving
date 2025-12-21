class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        long long total = 0;
        for(int i = 0; i < cost.size(); i++){
            total += cost[i];
        }
        unordered_map<char, long long> mpp;
        for(int i = 0; i < cost.size(); i++){
            mpp[s[i]] += cost[i];
        }
        if(mpp.size() <= 1) return 0;
        long long ans = total;
        for(auto it : mpp){
            ans = min(ans, total - it.second);
        }
        return ans;
    }
};