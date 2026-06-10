class Solution {
    bool isvalid(int n, int m, int i, int j){
        return (i < n && j < m && i >= 0 && j >= 0);
    }
    int bfs(queue<pair<int,int>>& q, int cnt, vector<vector<int>>& vis, vector<vector<int>>& grid,int n, int m){
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            cnt++;
            int dr[]=  {-1,0,1,0};
            int dc[] = {0,-1,0,1};
            for(int i = 0; i < 4; i++){
                int newr = row + dr[i];
                int newc = col + dc[i];
                if(isvalid(n,m, newr, newc) && grid[newr][newc] == 1 && vis[newr][newc] == 0){
                    q.push({newr, newc});
                    vis[newr][newc] = 1;
                }
            }
        }
        return cnt;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxi = INT_MIN;
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            for(int j  = 0; j < m; j++){
                if(grid[i][j] == 1 && vis[i][j] == 0){
                    q.push({i,j});
                    vis[i][j] = 1;
                    int cnt = bfs(q, 0, vis, grid, n, m);
                    maxi = max(maxi, cnt);
                }
            }
        }
        return maxi == INT_MIN?0: maxi;
    }
};