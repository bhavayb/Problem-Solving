class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        
        int j0 = y, j1 = k + y - 1;
        while(j0 <= j1){
            int i0 = x, i1 = k + x -1;
            while(i0 < i1){
                swap(grid[i0][j0], grid[i1][j0]);
                i0++;
                i1--;
            }
            j0++;
        }
        return grid;
    }
};