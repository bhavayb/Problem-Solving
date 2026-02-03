class Solution {
    vector<pair<int, int>> dir = {{-1,0}, {0, 1}, {1, 0}, {0, -1}};
    bool istrue(int r, int c, vector<vector<int>>& grid){
        if(r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size()){
            return true;
        }
        return false;
    }
    int bfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis){
        int cnt = 1;
        vis[r][c] = 1;
        queue<pair<int, int>> q; 
        q.push({r, c});
        while(!q.empty()){
            auto node = q.front();
            int row = node.first, col = node.second;
            q.pop();
            for(int i = 0; i < dir.size(); i++){
                int n_row = row + dir[i].first;
                int n_col = col + dir[i].second;
                if(istrue(n_row, n_col, grid) && !vis[n_row][n_col] && grid[n_row][n_col] == 1){
                    cnt++;
                    vis[n_row][n_col] = 1;
                    q.push({n_row, n_col});
                }
            }
        }
        return cnt;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans =0;
        for(int i = 0; i < m; i++){
            if(grid[0][i] == 1 && !vis[0][i]){
                int cnt = bfs(0, i, grid, vis);
                ans += cnt;
            }
            if(grid[n-1][i] == 1 && !vis[n-1][i]){
                int cnt = bfs(n-1, i, grid, vis);
                ans += cnt;
            }
        }

        for(int i = 0; i < n; i++){
            if(grid[i][0] == 1 && !vis[i][0]){
                int cnt = bfs(i, 0, grid, vis);
                ans += cnt;
            }
            if(grid[i][m-1] == 1 && !vis[i][m-1]){
                int cnt = bfs(i, m-1, grid, vis);
                ans += cnt;
            }
        }
        int ones = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1) ones++;
            }
        }
        return ones - ans;
    }
};