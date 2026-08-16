class Solution {
    int mod = 1e9 + 7;
    long long func(long long x, long long n){
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n%2 == 0) return func(x*x %mod, n/2);
        return x*func(x %mod, n-1)%mod;
    }
public:
    int countGoodNumbers(long long n) {
        
        return (long long)func(5, (n+1)/2)*func(4, n/2) % mod;
    }
};