class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1 || s.length() <= numRows) return s;
        vector<string> ans(numRows, "");

        int i = 0;
        int flag = 0;
        int j = 0;
        while(i < s.length()){
            if(flag == 0){
                while( j < numRows && i < s.length()){
                    ans[j] += s[i];
                    j++; i++;
                }
                flag = 1;
            }
            j = j-2;
            if(flag == 1){
                while(j > 0 && i < s.length()){
                    ans[j] += s[i];
                    j--; i++;
                }
                flag = 0;
            }
        }
        string final = "";
        for(auto it :  ans ){
            final += it;
        }
        return final;
    }
};