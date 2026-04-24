class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l = 0, r = 0;
        int underscore = 0;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'L'){
                l++;
            }else if(moves[i] == 'R') r++;
            else underscore++;
        }

        return max(abs(l-r+underscore), abs(r-l+ underscore));
    }
};