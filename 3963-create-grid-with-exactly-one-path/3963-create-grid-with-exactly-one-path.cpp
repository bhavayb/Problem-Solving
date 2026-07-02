class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> ans(m,vector<char>(n,'#'));

        for(int i = 0; i < m; i++){
            ans[i][0] = '.';
        }
        for(int i = 0; i < n; i++){
            ans[m-1][i] = '.';
        }
        vector<string> final;
        for(int i = 0; i < m; i++){
            string x = "";
            for(int j = 0; j < n; j++){
                x+= ans[i][j];
            }
            final.push_back(x);
        }
        return final;
    }
};