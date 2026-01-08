class Solution {
    private:
    int lcs(string s, string t, int i, int j, vector<vector<int>>& dp){
        if( i<0 || j<0) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] =  1 + lcs(s,t,i-1,j-1,dp);
        return dp[i][j] = max(lcs(s,t,i-1, j, dp), lcs(s,t,i,j-1,dp));
    }
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        // return lcs(str1, str2, n-1, m-1);
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s[i-1] == t[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        int i = n; int j = m;
        string ans = "";
        while( i > 0 && j > 0){
            if(s[i-1] == t[j-1]){
                ans+=t[j-1];
                i--; j--;
            }else if(dp[i-1][j] > dp[i][j-1]){
                ans += s[i-1];
                i--;
            }else{
                ans += t[j-1];
                j--;
            }
        }
        while( i > 0){
            ans+= s[i-1];
            i--;
        }
        while(j > 0){
            ans+= t[j-1];
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};