class Solution {
    private:
    int func(int i, int j, string& s, string& t, vector<vector<int>>& dp){
        if(j <0){
                int ans = 0;
                for(int x = 0; x <= i; x++){
                    ans += s[x];
                }
                return ans;

        }
        if(i < 0){
                int ans = 0;
                for(int x = 0; x <= j; x++){
                    ans += t[x];
                }
                return ans;
        }
        if(dp[i][j]  != -1) return dp[i][j] ;
        if(s[i] == t[j]){
            return dp[i][j] =  func(i-1, j-1, s, t,dp);
        }else{
            int left = s[i] + func(i-1, j, s,t,dp);
            int right = t[j] + func(i, j-1, s, t, dp);
            return dp[i][j] = min(left, right);
        }
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.length(), n = s2.length();
        vector<vector<int>> dp(m, vector<int>(n , -1));
        return func(m-1, n-1, s1, s2, dp);
    }
};