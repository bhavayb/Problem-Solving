class Solution {
public:
    void func(int i, int j,vector<vector<char>>& grid, vector<vector<int>>& vis, int n, int m){
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
        for(int k = 0; k < 4; k++){
            int newi = i + dr[k];
            int newj = j + dc[k];
            if(newi >= 0 && newj >= 0 && newi < n && newj <m && grid[newi][newj] == '1' && vis[newi][newj] == 0){
                vis[newi][newj] = 1;
                func(newi, newj, grid, vis, n,m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int i =0; i< n; i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j] == '1' && vis[i][j] == 0){
                    cnt++;
                    vis[i][j] = 1;
                    func(i, j, grid, vis, n, m);
                }
            }
        }
        return cnt;
    }
};