class Solution {
    vector<vector<int>> func(vector<vector<char>>& grid, char ch){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j != 0){
                    if(grid[i][j] == ch){
                        prefix[i][j] = 1 + prefix[i][j-1];
                    }else{
                        prefix[i][j] = prefix[i][j-1];
                    }
                }else{
                    prefix[i][j] = (grid[i][j] == ch);
                }
            }
        }
        for(int j = 0; j < m; j++){
            for(int i = 1; i < n; i++){ 
                prefix[i][j] += prefix[i-1][j];  
            }
        }

        return prefix;
    }

public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        vector<vector<int>> prefixX = func(grid, 'X');
        vector<vector<int>> prefixY = func(grid, 'Y');

        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(prefixX[i][j] == prefixY[i][j] && prefixX[i][j] > 0) ans++;
            }
        }
        return ans;
    }
};