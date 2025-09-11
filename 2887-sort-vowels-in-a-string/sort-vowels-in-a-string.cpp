class Solution {
    private:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            return true;
        }else return false;
    }
public:
    string sortVowels(string s) {
        vector<int> index;
        vector<char> vowel;
        for(int i = 0; i< s.length(); i++){
            if(isVowel(s[i])){
                vowel.push_back(s[i]);
                index.push_back(i);
            }
        }
        if(vowel.size() <=1) return s;
        
        sort(vowel.begin(), vowel.end());
        for(int i = 0; i< index.size(); i++){
            s[index[i]] = vowel[i];
        }
        return s;
    }
};