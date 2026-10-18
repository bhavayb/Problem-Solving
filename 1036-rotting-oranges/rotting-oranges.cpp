class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        // vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<vector<int>> q;
        for(int i =0; i < n; i++){
            for(int j = 0; j< m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }
            }
        }
        int time = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int i = it[0], j = it[1], t = it[2];
            time = t;
            for(int k = 0; k< 4; k++){
                int newi = i + dr[k];
                int newj = j + dc[k];

                if(newi >= 0 && newj >= 0 && newi < n && newj < m && grid[newi][newj] == 1){
                    // vis[newi][newj] = 1;
                    grid[newi][newj] = 2;
                    q.push({newi, newj, t+1});
                }
            }
        }
        for(int i =0; i < n; i++){
            for(int j =0; j < m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }
        return time;
    }
};