class Solution {
    void dfs(string s,vector<string>& ans, unordered_map<string, multiset<string>>& mpp ){
        while(mpp[s].size() != 0){
            string dummy = *mpp[s].begin();
            mpp[s].erase(mpp[s].begin());
            dfs(dummy, ans, mpp);
        }
        ans.push_back(s);
        return;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> mpp;
        for(int i =0; i < tickets.size(); i++){
            string f = tickets[i][0];
            string s = tickets[i][1];
            mpp[f].insert(s);
        }
        vector<string> ans;
        // ans.push_back("JFK");
        dfs("JFK", ans, mpp);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};