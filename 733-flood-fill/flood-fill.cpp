class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n =image.size(), m = image[0].size();
        int scolor = image[sr][sc];
        if (scolor == color) return image;

        queue<pair<int,int>> q;
        q.push({sr, sc});
        image[sr][sc] = color;
        while(!q.empty()){
            auto idx = q.front();
            q.pop();
            int i = idx.first, j = idx.second;
            int dr[] = {-1,0,1,0};
            int dc[] = {0, 1, 0, -1};
            for(int x = 0; x< 4; x++){
                int di = i + dr[x];
                int dj = j + dc[x];
                if(di >= 0 && di < n && dj >= 0 && dj < m){
                    if(image[di][dj] == scolor){
                        image[di][dj] = color;
                        q.push({di, dj});
                    }
                }
            }

        }
        return image;
    }
};