class Solution {
public:
    int minOperations(string s) {
        set<char> st;
        for(int i = 0 ; i< s.length(); i++){
            st.insert(s[i]);
        }
        int minOp = 0;
        vector<char> v(st.begin(), st.end());
        for(int  i = 0; i< v.size(); i++){
            if(v[i] != 'a'){
                if(i+1 < v.size()){
                    minOp += v[i+1] - v[i];
                }else{
                    minOp += 'z' - v[i] +1;
                }
            }
        }
        return minOp;
    }
};