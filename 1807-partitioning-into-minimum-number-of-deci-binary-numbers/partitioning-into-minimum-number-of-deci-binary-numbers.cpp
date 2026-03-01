class Solution {
public:
    int minPartitions(string n) {
        int x = n.length();
        int maxi = -1;
        for(int i = 0;  i < x; i++){
            if(maxi < (int)(n[i])) maxi = (int)n[i];
        }
        return maxi- 48;
    }
};