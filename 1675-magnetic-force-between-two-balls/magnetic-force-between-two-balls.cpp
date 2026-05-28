class Solution {
    bool func(vector<int>& arr, int mindist, int m){
        int cnt= 1;
        int last = arr[0];
        for(int i =1; i< arr.size(); i++){
            if(arr[i] - last >= mindist){
                last = arr[i];
                cnt++;
            }
        }
        if(cnt >= m)return true;
        return false;
    }
public:
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1; int high = position[position.size()-1] - position[0];
        // for(int i = low; i<= high; i++){
        //     if(func(position, i, m) == false) return i-1;
        // }
        // return 0;
        int ans = 0;
        while(low <= high){
            int mid = (low+high)/2;
            
            if(func(position, mid, m) == true){
                low  = mid + 1;
                ans = mid;
            }else high = mid -1;
        }
        return ans;
    }
};