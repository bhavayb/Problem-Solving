class Solution {
    void func(int sr, int sc, int color, int scolor,
              vector<vector<int>>& image) {

        int n = image.size();
        int m = image[0].size();

        if (sr < 0 || sc < 0 || sr >= n || sc >= m)
            return;

        if (image[sr][sc] != scolor)
            return;

        image[sr][sc] = color;

        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            func(sr + dr[i], sc + dc[i], color, scolor, image);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int scolor = image[sr][sc];

        if (scolor == color)
            return image;

        func(sr, sc, color, scolor, image);

        return image;
    }
};