class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(j != 0){
                    grid[i][j] += grid[i][j-1];
                }
            }
        }
        for(int j = 0; j < grid[0].size(); j++){
            for(int i = 0; i < grid.size(); i++ ){
                if(i != 0){
                    grid[i][j] += grid[i-1][j];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] <= k) ans++;
            }
        }
        return ans;
    }
};