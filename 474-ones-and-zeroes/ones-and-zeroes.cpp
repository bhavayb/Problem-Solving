class Solution {
pair<int,int>count(const string &strs){
    int numzero=0;
    int numone=0;
    for(char ch:strs)
    {
        if(ch=='0') numzero++;
        if(ch=='1') numone++;

    }
    return{numzero,numone};

}

int length(int index,vector<string>&strs,int m, int n,int zerocount,int onecount,vector<vector<vector<int>>>&dp)
{
    if(index==strs.size()) return 0;
    if(zerocount==m && onecount==n) return 0;
    if(dp[index][zerocount][onecount]!=-1) return dp[index][zerocount][onecount];
    pair<int,int>freq=count(strs[index]);
    int zerofreq=freq.first;
    int onefreq=freq.second;
    int take=0;
    if(zerocount+zerofreq<=m && onecount+onefreq<=n){
        take=1+length(index+1,strs,m,n,zerocount+zerofreq,onecount+onefreq,dp);
    }
        int nottake=length(index+1,strs,m,n,zerocount,onecount,dp);

        return dp[index][zerocount][onecount]=max(take,nottake);

}
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>>dp(strs.size(),vector<vector<int>>(m+1,vector<int>(n+1,-1)));
         return length(0,strs,m,n,0,0,dp);
    }
};