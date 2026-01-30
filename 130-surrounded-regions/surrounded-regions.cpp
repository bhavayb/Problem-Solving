class Solution {
    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[i][j] = 1;
        for(auto it: dir){
            int n_row = i + it[0], n_col = j + it[1];
            if(n_row >= 0 && n_row < board.size() && n_col >= 0 && n_col < board[0].size() && vis[n_row][n_col] == 0 && board[n_row][n_col] == 'O'){
                dfs(n_row, n_col, board, vis);
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int j = 0; j < m; j++){
            if(board[0][j] == 'O'){
                dfs(0, j, board, vis);
            }
        }
        for(int j = 0; j < m; j++){
            if(board[n-1][j] == 'O'){
                dfs(n-1, j, board, vis);
            }
        }
        for(int i = 0; i < n; i++){
            if(board[i][0] == 'O'){
                dfs(i, 0, board, vis);
            }
        }
        for(int i = 0; i < n; i++){
            if(board[i][m-1] == 'O'){
                dfs(i, m-1, board, vis);
            }
        }

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j] == 'O' && vis[i][j] != 1){
                    board[i][j] = 'X';
                }
            }
        }
    }
};