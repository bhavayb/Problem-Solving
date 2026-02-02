class Solution{
    vector<pair<int,int>> dir= { {-1,0}, {0,1}, {1,0},  {0,-1}};
    void bfs(int i, int j, vector<vector<char>> & grid, vector<vector<int>> &vis){
        vis[i][j]  = 1;
        queue<pair<int, int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;
            for(int x = 0; x < dir.size(); x++){
                int n_row= row + dir[x].first;
                int n_col = col + dir[x].second;
                if(n_row >= 0 && n_col >= 0 && n_row < grid.size() && n_col < grid[0].size() && !vis[n_row][n_col] && grid[n_row][n_col] == '1'){
                    q.push({n_row, n_col});
                    vis[n_row][n_col] = 1;
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>> &grid){
        // grid to adjlist
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> ( m , 0));
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1' && !vis[i][j]){
                    bfs(i, j, grid, vis);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};