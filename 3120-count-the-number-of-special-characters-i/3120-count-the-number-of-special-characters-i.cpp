class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s;
        for(auto ch : word){
            s.insert(ch);
        }
        int ans = 0;
        for(auto it : s){
            if(it >= 'a' && it <= 'z'){
                char x = it  -32;
                if(s.find(x) != s.end()) ans++;
            }
        }
        return ans;
    }
};