class Solution {
public:
    int maxDistance(string moves) {
        int u = 0, d = 0, r = 0, l = 0, under = 0;
        for(int i = 0; i < moves.length(); i++){
            if(moves[i] == 'U') u++;
            else if(moves[i] == 'D') d++;
            else if(moves[i] == 'L') l++;
            else if(moves[i] == 'R') r++;
            else under++;
        }
        return abs(u-d) + abs(r-l) + under;
    }
};