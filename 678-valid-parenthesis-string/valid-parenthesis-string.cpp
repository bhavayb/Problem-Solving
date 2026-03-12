class Solution {
    private:
    bool helper(string s, int idx , int count, vector<vector<int>>& dp){
        // base case
        if(count < 0) return false;
        if(idx == s.length()) return (count == 0);
        if(dp[count][idx] != -1) return dp[count][idx];
        bool ans = false;
        if(s[idx] == ')') ans = helper(s, idx+1, count -1, dp);
        
        else if(s[idx] == '(') ans = helper(s, idx+1, count+1, dp);
        else{
            for(int i = -1; i <= 1; i++){
                ans = ans || helper(s,idx+1, count+i, dp);
            }
        }
        return dp[count][idx] = ans;
    }
public:
    bool checkValidString(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return helper(s, 0, 0, dp);
    }
};