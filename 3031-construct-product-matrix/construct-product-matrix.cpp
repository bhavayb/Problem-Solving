class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int x=n*m;
        vector <int> ans;
        vector <long long> pre(x,1);
        vector <long long> suf(x,1);
        for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
            ans.push_back(grid[i][j]);
           }
        }
        for(int i=1;i<x;i++){
            pre[i]=(pre[i-1]*ans[i-1])%12345;
        }
        for(int i=x-2;i>=0;i--){
            suf[i]=(suf[i+1]*ans[i+1])%12345;
        }
        vector <vector <int>> req(n,vector <int> (m));
        for(int i=0;i<x;i++){
            long long a=(pre[i]*suf[i])%12345;
            req[i/m][i%m]=a;
        }
        return req;
    }
};