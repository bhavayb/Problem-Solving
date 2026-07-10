class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        ans.push_back({intervals[0][0], intervals[0][1]});
        int n = intervals.size();
        for(int i = 1; i< n; i++){
            int currst = intervals[i][0];
            int currend = intervals[i][1];
            int st = ans.back()[0];
            int end = ans.back()[1];

            if(currst > end){
                ans.push_back({currst, currend});
            }else{
                if(currst <= end){
                    if(currend > end){
                        ans[ans.size()-1] = {st, currend};
                    }
                }
            }
        }
        return ans;
    }
};