class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char,int> mpp;
        for(int i = 0; i < order.size(); i++){
            mpp[order[i]] = i;
        }
        for(int i = 0; i < words.size()-1; i++) {
            string s1 = words[i];
            string s2 = words[i+1];
            bool flag = true;
            for(int j = 0; j < min(s1.size(), s2.size()); j++){
                if(s1[j] != s2[j]) {
                    flag = false;
                    if(mpp[s1[j]] > mpp[s2[j]]){
                        return false;
                    }
                    break;
                }
            }
            if(flag == true && s1.size() > s2.size()) return false;
        }
        return true;
    }
};