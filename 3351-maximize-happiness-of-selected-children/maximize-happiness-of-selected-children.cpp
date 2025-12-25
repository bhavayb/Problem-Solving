class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end());
        long long ans = 0;
        int count = 0;
        int i = happiness.size()-1;
        while(i >= 0 && k > 0){
            if(happiness[i] - count > 0){
                ans += (happiness[i] - count);
            }
            i--; k--;
            count++;
        }
        return ans;
    }
};