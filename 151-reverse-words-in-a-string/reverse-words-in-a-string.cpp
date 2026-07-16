class Solution {
public:
    string reverseWords(string s) {
        vector<string> ans;
        string t = "";
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] != ' '){
                t += s[i];
            }else{
                if(t != ""){
                    ans.push_back(t);
                    t = "";
                }
            }
        }
        if(t!= "") ans.push_back(t);
        string final = "";

        for(int i = ans.size()-1; i>=0 ; i--){
            final += ans[i];
            if(i>0) final += ' ';
        }
        return final;
    }
};