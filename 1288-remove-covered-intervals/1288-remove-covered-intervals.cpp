class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1; i< n; i++){
            int a= intervals[i][0];
            int b = intervals[i][1];
            auto it = ans.back();
            int c = it[0];
            int d = it[1];
            if(c<= a && b <= d) continue;
            else if(c == a && b > d){
                d = b;
                ans.pop_back();
                ans.push_back({c,d});
                continue;
            }
            else ans.push_back(intervals[i]);
        }
        return ans.size();
    }
};