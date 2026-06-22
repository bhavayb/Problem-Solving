class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<int,int> mpp;
        for(auto it: text){
            mpp[it]++;
        }
        //string s = "balloon";
        // b->1
        //a->1
        //l->2
        // o->2
        // n->1
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        for(auto it: mpp){
            if(it.first == 'b') b = it.second;
            if(it.first == 'a') a = it.second;
            if(it.first == 'l') l = it.second/2;
            if(it.first == 'o') o = it.second/2;
            if(it.first == 'n') n = it.second;
        }
        // if(b == a && a == l && l == o && o == n && n == b){
        //     return b;
        // }
        if(b>0 && a > 0 && l > 0 && o > 0 && n > 0 ){
            return min(b,min(a,min(l,min(o,n))));
        }
        else return 0;
    }
};