class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int countA = 0; int countB = 0;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == 'a'){
                countA++;
            }else{
                countB++;
            }
        }
        return s.length() - 2*min(countA, countB);
    }
};