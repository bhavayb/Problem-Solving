class Solution {
    int func(int n){
        vector<int> digits;
        while(n> 0){
            digits.push_back(n%10);
            n = n/10;
        }
        int cnt = 0;
        for(int i = 1; i < digits.size()-1; i++){
            if(digits[i] > digits[i-1] && digits[i] > digits[i+1]){
                cnt++;
            }else if(digits[i] < digits[i-1] && digits[i] < digits[i+1]){
                cnt++;
            }
        }
        return cnt;
    }
public:
    int totalWaviness(int num1, int num2) {
        int val  = 0;
        for(int i = num1; i <= num2; i++){
            if(i >= 100) val += func(i);
        }
        return val;
    }
};