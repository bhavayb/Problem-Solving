class Solution {
    bool func(vector<int>& candies, long long k, long long candy ){
        long long child = 0;
        // int cnt = 0;
        for(int  i= 0; i < candies.size(); i++){
            child += (candies[i]/candy);
        }
        if(child >= k) return true;
        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long low = 1;
        long long high = 0;

        for(int i = 0; i < candies.size(); i++){
            high += candies[i];
        }
        if(k > high) return 0;
        // // int ans = 0;
        // for(int candy = low ; candy <= high; candy++){
        //     if(func(candies, k, candy ) == false) return candy-1;
        // }
        // return 0;

        while(low <= high){
            long long mid = (low + high)/2;
            if(func(candies, k, mid) == true) low = mid +1;
            else high = mid - 1;
        }
        return high;
    }
};