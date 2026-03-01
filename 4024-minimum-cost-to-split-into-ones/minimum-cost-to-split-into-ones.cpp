class Solution {
public:
    int minCost(int n) {
        int ans = 0;
        int temp = n;
        while(n > 1){
            ans += n-1;
            n--;
        }
        return ans;
    }
};