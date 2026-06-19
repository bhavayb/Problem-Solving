class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> ans;
        ans.push_back(0);
        for(int i =0; i < gain.size(); i++ ){
            int val = ans[ans.size()-1];
            ans.push_back(val + gain[i]);
        } 
        return *max_element(ans.begin(), ans.end());
    }
};