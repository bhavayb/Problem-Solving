class Solution {
public:
    long long removeZeros(long long n) {
        string s = "";
        while(n > 0){
            long long rem = n%10;
            if(rem != 0) s+= (char)(n%10 + '0');
            n = n/10;
        }
        reverse(s.begin(), s.end());
        return stoll(s);
    }
};