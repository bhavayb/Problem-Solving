class Solution {
    vector<int> di = {-1,0,1,0};
    vector<int> dj = {0, 1,0,-1};
private:
    void func(int i, int j,vector<vector<int>>& grid, vector<vector<int>>& vis, long long& sum){
        vis[i][j] = 1;
        sum += grid[i][j];
        for(int k =0; k< 4; k++ ){
            int newi = di[k] + i;
            int newj = dj[k] + j;
            if(newi >= 0 && newi < grid.size() && newj >= 0 && newj < grid[0].size() && !vis[newi][newj] && grid[newi][newj] != 0){
                func(newi, newj, grid, vis, sum);
            }
        }
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int cnt = 0;
        int m = grid.size(); int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    long long sum = 0;
                    func(i, j, grid, vis, sum);
                    if(sum%k == 0) cnt += 1;
                }
            }
        }
        return cnt;
    }
};