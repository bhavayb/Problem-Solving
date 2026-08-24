class Solution {
    int func(int i, int one, int zero, int m, int n, vector<pair<int,int>>& vec,vector<vector<vector<int>>> &dp ){
        if(i >= vec.size())return 0;
        if(dp[i][one][zero]!= -1)return dp[i][one][zero];
        int take = 0;
        if(vec[i].first + zero <= m && vec[i].second + one <= n){
            take = 1 + func(i+1, vec[i].second+one, vec[i].first+zero, m, n, vec, dp);
        }
        int nottake = func(i+1, one, zero, m, n, vec,dp);
        return dp[i][one][zero] = max(take, nottake);
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> vec;
        for(int i =0;i< strs.size(); i++){
            int zeros = 0; int ones = 0;
            for(int j = 0; j < strs[i].length(); j++){
                if(strs[i][j] == '1')ones++;
                else zeros++;
            }
            vec.push_back({zeros,ones});
        }
        int z = vec.size();
        vector<vector<vector<int>>> dp(z, vector<vector<int>>(n+1, vector<int>(m+1, -1)));
        return func(0, 0, 0, m, n, vec, dp);
    }
};