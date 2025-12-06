class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        string word;
        for (char c : s) {
            if (c != ' ') {
                word += c;
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }

        s.clear();
        for (int i = words.size() - 1; i >= 1; i--) {
            s += words[i];
            s += " ";
        }
        s += words[0];
        return s;
    }
};