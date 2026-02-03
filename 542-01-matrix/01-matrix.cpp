class Solution {
    private:
    vector<pair<int, int>> dir = {{-1,0},{0,1}, {1, 0}, { 0, -1}};
    bool istrue(int r, int c, int n, int m){
        if(r >= 0 && c >= 0 && r < n && c < m){
            return true;
        }
        return false;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m,0));
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>,int>> q;
        for(int i =0 ;i < n; i++){
            for(int j = 0; j< m; j++){
                if(mat[i][j] == 0){
                    q.push({{i,j}, 0});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            auto node = q.front();
            int row = node.first.first;
            int col = node.first.second;
            int steps = node.second;
            q.pop();
            dist[row][col] = node.second;
            for(int i = 0; i < dir.size(); i++){
                int n_row = row + dir[i].first, n_col = col + dir[i].second;
                if(istrue(n_row, n_col, n, m) && vis[n_row][n_col] == 0){
                    q.push({{n_row, n_col}, steps+1});
                    vis[n_row][n_col] = 1;
                }
            }
        }
        return dist;
    }
};