class Solution {
public:
    int totalMoney(int n) {
        int grp = n/7;
        int total = 0;
        int val = 1;
        int inigrp = grp;
        while(grp > 0){
            total += (3.5)*(2*val + 6);
            val++;
            grp--;
        }
        int left = n - inigrp*7;
        for(int i = 0 ; i< left; i++){
            total += val + i;
        }
        return total;
    }
};