class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mpp;
        for(auto num: nums){
            mpp[num]++;
        }
        vector<pair<int, int>> freqVec;
        for (auto& it : mpp) {
            freqVec.push_back({it.second, it.first});
        }
        sort(freqVec.begin(), freqVec.end());

        vector<int> ans;
        int idx = freqVec.size() - 1;
        while (k > 0 && idx >= 0) {
            ans.push_back(freqVec[idx].second);
            idx--;
            k--;
        }
        return ans;
    }
};