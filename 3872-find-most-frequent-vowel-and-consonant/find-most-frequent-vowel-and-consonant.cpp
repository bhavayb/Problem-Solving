class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> vowels(26, 0);
        vector<int> consonants(26, 0);

        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowels[c - 'a']++;
            } else {
                consonants[c - 'a']++;
            }
        }

        int v = 0, c = 0;
        for (int cnt : vowels)
            v = max(v, cnt);
        for (int cnt : consonants)
            c = max(c, cnt);

        return v + c;
    }
};
