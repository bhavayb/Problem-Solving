class Solution {
    typedef long long ll;
public:
    long long sumAndMultiply(int n) {
        ll sum = 0;
        ll num = 0;
        int powwer = 0;
        while(n > 0){
            int val  =n%10;
            if(val != 0){
                sum += val;
                num+= val*pow(10, powwer);
                powwer++;
            }
            n = n/10;
        }
        return (ll)(sum*num);
    }
};