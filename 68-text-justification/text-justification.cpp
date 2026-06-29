class Solution {
    pair<string,int> func(vector<string>& words, int i, int maxWidth){
        int len = 0;
        string ans = "";
        while(i < words.size()){
            int need = words[i].size() + (ans.empty() ? 0 : 1);
            if(len + need > maxWidth) break;
            if(!ans.empty()){
                ans += ' ';
                len++;
            }
            ans += words[i];
            len += words[i].size();
            i++;
        }
        return {ans, i};
    }

    string helper(string s, int maxWidth, bool lastLine){
        vector<string> words;
        string temp = "";
        int cnt = 0;
        for(char c : s){
            if(c == ' '){
                cnt += temp.size();
                words.push_back(temp);
                temp = "";
            }
            else{
                temp += c;
            }
        }

        if(!temp.empty()){
            cnt += temp.size();
            words.push_back(temp);
        }
        if(lastLine || words.size() == 1){
            string ans = words[0];

            for(int i = 1; i < words.size(); i++){
                ans += " ";
                ans += words[i];
            }

            ans += string(maxWidth - ans.size(), ' ');
            return ans;
        }

        int gaps = words.size() - 1;
        int spaces = maxWidth - cnt;
        int even = spaces / gaps;
        int extra = spaces % gaps;
        string ans = words[0];

        for(int i = 1; i < words.size(); i++){
            ans += string(even, ' ');
            if(extra > 0){
                ans += ' ';
                extra--;
            }

            ans += words[i];
        }

        return ans;
    }

public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> vec;
        int i = 0;
        while(i < words.size()){
            auto it = func(words, i, maxWidth);
            bool lastLine = (it.second == words.size());
            vec.push_back(helper(it.first, maxWidth, lastLine));
            i = it.second;
        }

        return vec;
    }
};