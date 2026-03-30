class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string s1odd = "";
        string s2even = ""; 
        string s1even = "";
        string s2odd = "";
        for(int i = 0; i < s1.length(); i++){
            if(i%2 == 1){
                s1odd += s1[i];
                s2odd += s2[i];
            }else {
                s1even += s1[i];
                s2even += s2[i];
            }
        }
        sort(s1odd.begin(), s1odd.end());
        sort(s2odd.begin(), s2odd.end());
        sort(s1even.begin(), s1even.end());
        sort(s2even.begin(), s2even.end());

        if(s1odd == s2odd && s1even == s2even) return true;
        return false;
    }
};