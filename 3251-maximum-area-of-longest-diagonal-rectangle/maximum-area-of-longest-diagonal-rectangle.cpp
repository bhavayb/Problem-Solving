class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxArea = 0;
        int maxDiagonalSq = -1;

        for (auto &dim : dimensions) {
            int l = dim[0];
            int b = dim[1];
            int diagSq = l * l + b * b;
            int area = l * b;

            if (diagSq > maxDiagonalSq) {
                maxDiagonalSq = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiagonalSq && area > maxArea) {
                maxArea = area;
            }
        }
        return maxArea;
    }
};
