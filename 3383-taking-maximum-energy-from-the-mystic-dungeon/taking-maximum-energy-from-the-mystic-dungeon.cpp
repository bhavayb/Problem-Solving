class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        vector<int> ans = energy;
        int n= energy.size();
        for(int i = n - k-1; i>= 0; i-- ){
            ans[i] += ans[i+k];
        }
        sort(ans.begin(), ans.end());
        return ans[n-1];
    }
};