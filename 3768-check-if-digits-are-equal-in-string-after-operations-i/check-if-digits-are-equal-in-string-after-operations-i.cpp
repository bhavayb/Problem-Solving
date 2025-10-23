class Solution {
public:
    bool hasSameDigits(string s) {

        string x = "";
        int l = s.length();
        while(l > 2){
            for(int i = 0; i<s.length()-1; i++){
                int y = ((int)(s[i]-'0') + (int)(s[i+1])-'0') %10;
                x += (char)(y+'0');
            }
            s = x;
            x="";
            l--;
        }
        if(s[0] == s[1]) return true;
        else return false;
    }
};