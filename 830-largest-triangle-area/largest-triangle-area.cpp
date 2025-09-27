class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;
        int n = points.size();

        auto dist = [](const vector<int>& a, const vector<int>& b) {
            // Euclidean distance between two points
            return sqrt((a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1]));
        };

        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                for (int k = j + 1; k < n; ++k) {
                    double a = dist(points[i], points[j]);
                    double b = dist(points[j], points[k]);
                    double c = dist(points[k], points[i]);
                    double s = (a + b + c) / 2.0; // semi-perimeter
                    double area = sqrt(s * (s - a) * (s - b) * (s - c)); // Heron's formula
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};
