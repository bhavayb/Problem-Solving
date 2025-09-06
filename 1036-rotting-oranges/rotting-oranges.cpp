class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int fresh = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({i, j});
                    vis[i][j] = 1;
                }
                if(grid[i][j] == 1) fresh++;
            }
        }

        if(fresh == 0) return 0;

        int time = 0;
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, -1, 0, 1};
        while(!q.empty()) {
            int sz = q.size();
            bool rotted = false;

            while(sz--) {
                auto [x, y] = q.front();
                q.pop();

                for(int dir = 0; dir < 4; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if(nx >= 0 && ny >= 0 && nx < n && ny < m &&
                       grid[nx][ny] == 1 && !vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        grid[nx][ny] = 2; 
                        q.push({nx, ny});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            if(rotted) time++;
        }

        return fresh == 0 ? time : -1;
    }
};
