class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int c = 9;
        string s = "";
        while(num != 0 && c >= 0){
            if(c <= sum){
                s+= to_string(c);
                sum -= c;
                num--;
            }else{
                c--;
            }
        }
        return sum == 0 ? s : "";
    }
};