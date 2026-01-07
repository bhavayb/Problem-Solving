class Solution {
    private:
    int func(string str1, string str2, int i, int j, vector<vector<int>>& dp){
		if(i < 0 || j < 0){
			return 0;
		}
		if(dp[i][j] != -1) return dp[i][j];
		if(str1[i] == str2[j]) return dp[i][j] = 1 + func(str1, str2, i-1, j-1, dp);
		
		return dp[i][j] = max(func(str1, str2, i, j-1, dp), func(str1, str2, i-1, j, dp));

	}

public:
    int minDistance(string word1, string word2) {
        int n = word1.length(); int m = word2.length();
	    vector<vector<int>> dp(n,vector<int>(m,-1));
		int x = func(word1, word2, n-1, m-1, dp) ;
        return (n-x) + (m-x);
    }
};