class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < nums.size(); i++){
            mpp[nums[i]].push_back(i);
        }

        int n = nums.size();
        vector<int> ans(queries.size());

        for(int i = 0; i < queries.size(); i++){
            int idx = queries[i];
            int val = nums[idx];

            auto &vec = mpp[val];

            if(vec.size() == 1){
                ans[i] = -1;
                continue;
            }

            auto it = lower_bound(vec.begin(), vec.end(), idx);
            int pos = it - vec.begin();

            int res = INT_MAX;

            int next = vec[(pos + 1) % vec.size()];
            int d1 = abs(next - idx);
            res = min(res, min(d1, n - d1));

            int prev = vec[(pos - 1 + vec.size()) % vec.size()];
            int d2 = abs(prev - idx);
            res = min(res, min(d2, n - d2));

            ans[i] = res;
        }

        return ans;
    }
};