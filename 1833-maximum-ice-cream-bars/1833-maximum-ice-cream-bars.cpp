class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < costs.size(); i++){
            if(sum + costs[i] <= coins) {
                ans++;
                sum += costs[i];
            }else break;
        }
        return ans;
    }
};