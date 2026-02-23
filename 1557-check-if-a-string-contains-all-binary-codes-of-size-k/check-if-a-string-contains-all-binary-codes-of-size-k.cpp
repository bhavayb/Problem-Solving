class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int i = s.length() - k;
        unordered_set<string> st;
        while(i >= 0){
            string temp  = s.substr(i, k);
            st.insert(temp);
            i--;
        }
        return st.size() == pow(2,k);
    }
};