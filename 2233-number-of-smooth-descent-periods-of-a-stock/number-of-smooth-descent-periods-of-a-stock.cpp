class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long count = prices.size();
        int i = 0, j = 1;
        while( i < prices.size() && j < prices.size()){
            if(prices[j] - prices[j-1] == -1){
                count += j-i;
                j++;
            }else{
                i = j;
                j++;
            }
        }
        return count;

    }
};