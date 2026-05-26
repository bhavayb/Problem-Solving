class Solution {
private:
    int func(vector<int>& arr, int days, int k){
        int count = 0;
        int n = arr.size();
        int bouquets = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] <= days){
                count++;
                if(count == k){
                    bouquets++;
                    count = 0;
                }
            }else count = 0;
        }
        return bouquets;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int low = 1; 
        int high = -1;
        for(int i = 0; i< bloomDay.size(); i++){
            if(bloomDay[i] > high) high = bloomDay[i];
        }
        int ans= -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            int bouquets = func(bloomDay, mid, k);
            if(bouquets >= m){
                ans = mid;
                high = mid -1;
            }else low = mid+1;
        }
        return ans;
    }
};