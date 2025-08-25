class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> ans;
        for (int d = 0; d < m + n - 1; d++) {
            if (d % 2 == 0) {
                int x = min(d, m - 1);
                int y = d - x;
                while (x >= 0 && y < n) {
                    ans.push_back(mat[x][y]);
                    x--;
                    y++;
                }
            } else {
                int y = min(d, n - 1);
                int x = d - y;
                while (y >= 0 && x < m) {
                    ans.push_back(mat[x][y]);
                    x++;
                    y--;
                }
            }
        }

        return ans;
    }
};

