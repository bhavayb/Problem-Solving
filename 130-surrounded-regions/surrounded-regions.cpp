class Solution {
    bool isvalid(int r, int c, int n, int m){
        return (r >= 0 && c>= 0 && r < n && c <m);
    }
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(); int m = board[0].size();

        vector<vector<char>> d(n, vector<char>(m,'X'));
        vector<vector<int>> vis(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                q.push({i,0});
                vis[i][0] = 1;
            }
            if(board[i][m-1] == 'O'){
                q.push({i,m-1});
                vis[i][m-1] = 1;
            }
        }
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O'){
                q.push({0,j});
                vis[0][j] = 1;
            }
            if(board[n-1][j] == 'O'){
                q.push({n-1,j});
                vis[n-1][j] = 1;
            }
        }
        int dr[] = {-1,0,1,0};
        int dc[] = {0,-1,0,1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            d[r][c] = 'O';
            for(int i = 0; i < 4; i++){
                int nrow = r + dr[i];
                int ncol = c + dc[i];
                if(isvalid(nrow,ncol,n,m) && vis[nrow][ncol] == 0 && board[nrow][ncol] == 'O'){
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                } 
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                board[i][j] = d[i][j];
            }
        }
    }
};