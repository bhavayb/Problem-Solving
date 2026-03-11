class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        int ans = 0;
        int power = 1;
        while(n > 0){
            int bit = n % 2;     
            int flip = 1 - bit;  
            ans += flip * power;
            power *= 2;
            n /= 2;
        }
        return ans;
    }
};