class Solution {
    bool func(int x, int t){
        long long prod= 1;
        while(x > 0){
            prod *= (long long)(x%10);
            x = x/10;
        }
        return (prod%t == 0);
    }
public:
    int smallestNumber(int n, int t) {
        bool flag = true;
        while(flag){
            if(func(n, t) == true){
                return n;
            }
            n++;
        }
        return 1e9;
    }
};