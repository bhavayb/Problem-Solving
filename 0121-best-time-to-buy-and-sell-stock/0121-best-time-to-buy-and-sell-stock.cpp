class Solution{
public:
    int maxProfit(vector<int> arr){
        int n = arr.size();
        vector<int> maxiarray(n, INT_MIN);
        maxiarray[n-1] = arr[n-1];
        int maxprofit = INT_MIN;
        for(int i = n-2; i>= 0; i--){
            maxiarray[i] = max(arr[i], maxiarray[i+1]);
            maxprofit = max(maxprofit, maxiarray[i] - arr[i]);
        }
        return maxprofit;
    }
};