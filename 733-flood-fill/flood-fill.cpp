class Solution {
    void func(int sr, int sc, int color, int scolor, vector<vector<int>>& image, vector<vector<int>>& vis){
        if(sr<0 || sc< 0 || sr >= image.size() || sc >= image[0].size()) return;
        if(vis[sr][sc] == 1) return;
        if(image[sr][sc] != scolor) {
            vis[sr][sc] = 1;
            return;
        }
        if(image[sr][sc] == scolor)image[sr][sc] = color;
        vis[sr][sc] = 1;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};
        for(int i =0; i< 4; i++){
            func(sr+dr[i], sc+dc[i], color, scolor, image, vis);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int scolor = image[sr][sc];
        int n = image.size(); int m = image[0].size();
        vector<vector<int>> vis(n, vector<int>(m,0));
        func( sr,  sc,  color, scolor , image, vis);
        return image;
    }
};