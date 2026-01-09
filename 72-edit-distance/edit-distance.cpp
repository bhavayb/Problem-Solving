class Solution {
    // private:
    // int func(string s, string t, int i , int j, vector<vector<int>> dp){
    //     if( i< 0) return j+1;
    //     if(j < 0) return i+1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i] == t[j]) return dp[i][j] = func(s,t,i-1,j-1,dp);
    //     return dp[i][j] = 1 + min(func(s,t,i-1,j, dp), min(func(s,t,i-1,j-1, dp),func(s,t,i,j-1, dp)));
    // }
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        // return func(word1, word2, n-1, m-1, dp);
        for(int j = 0; j <= m; j++){
            dp[0][j] = j;
        }
        for(int i = 0; i <= n; i++){
            dp[i][0] = i;
        }
        for(int  i =1; i <=n ; i++){
            for(int j = 1; j <=m; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j]= dp[i-1][j-1];
                else{
                    dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};