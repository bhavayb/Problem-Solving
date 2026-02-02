class Solution {
    private:
    vector<pair<int,int>> dir =  {{-1,0}, {0, 1}, {1, 0}, {0,-1}};
    void bfs(int r, int c, vector<vector<int>>& image, vector<vector<int>> &vis, int inicolor, int newcolor){
        queue<pair<int, int>> q;
        int n = image.size();
        int m = image[0].size();
        q.push({r,c});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int row = node.first;
            int col = node.second;
            image[row][col] = newcolor;
            for(int i = 0; i < dir.size(); i++){
                int n_row = row + dir[i].first, n_col = col + dir[i].second;
                if(n_row >= 0 && n_col >= 0 && n_row < n && n_col < m && !vis[n_row][n_col] && image[n_row][n_col] == inicolor){
                    q.push({n_row, n_col});
                    vis[n_row][n_col] = 1;
                }
            }

        }
    }
   public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor) {
        int inicolor = image[sr][sc];
        int n = image.size(), m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bfs(sr, sc, image, vis, inicolor, newColor);
        return image;
    }
};
