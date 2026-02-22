class Solution {
public:
    bool isDigitorialPermutation(int n) {
        vector<int> fac(10);
        fac[0] = 1;
        for(int i =1; i < 10; i++){
            int cal = fac[i-1]*i;
            fac[i] = cal;
        }
        long long ans = 0;
        int temp = n;
        map<long long, long long> mpp1;
        while(n > 0){
            int rem = n%10;
            mpp1[rem]++;
            ans += fac[rem];
            n = n/10;
        }
        map<long long, long long> mpp2;
        while(ans>0){
            mpp2[ans%10]++;
            ans = ans/10;
        }
        return mpp1 == mpp2;
        
    }
};