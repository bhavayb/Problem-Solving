class Solution {
public:
    int canBeTypedWords(string text, string br) {
        vector<int> mp(26,0);
        int n=br.length();
        for(int i=0;i<n;i++){
            mp[br[i]-'a']=1;
        }
        int i=0,m=text.length(),count=0;
        while(i<m){
            bool flag=false;
            while(i<m && text[i]!=' '){
                if(mp[text[i]-'a']==1){
                    flag=true;
                }
                i++;
            }
            if(!flag){
               count++;
            }
            i++;
        }
        return count;
    }
};