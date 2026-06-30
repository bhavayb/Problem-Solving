class Solution {
    typedef long long ll;
public:
    long long countVowels(string word) {
        ll ans = 0;
        int n = word.size();

        for (int i = 0; i < n; i++) {
            if (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                word[i] == 'o' || word[i] == 'u') {
                ans += 1LL*(i+1)*(n-i);
            }
        }

        return ans;






        // int n = word.size();
        // for(int i = 0; i < n; i++){
        //     ll cnt = 0;
        //     set<char> st;
        //     for(int j = i; j< n; j++){
        //         st.insert(word[j]);
        //         if(st.find('a') != st.end() || st.find('e') != st.end() || st.find('i') != st.end() || st.find('o') != st.end()|| st.find('u') != st.end()){
        //             cnt++;
        //         }
        //     }
        //     sum += cnt;
        // }
        // return sum;
    }
};