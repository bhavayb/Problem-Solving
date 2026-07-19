class Solution {
public:
    string smallestSubsequence(string s) {
        unordered_map<char, int> mpp;
        for (int i = 0; i < s.length(); i++) {
            mpp[s[i]] = i;
        }
        vector<bool> flag(26, false);
        stack<char> st;
        int i = 1;
        st.push(s[0]);
        flag[s[0] - 'a'] = true;
        while (i < s.length()) {
            if (flag[s[i] - 'a']) {
                i++;
                continue;
            }
            while (!st.empty() && st.top() > s[i] && mpp[st.top()] > i) {
                flag[st.top() - 'a'] = false;
                st.pop();
            }
            st.push(s[i]);
            flag[s[i] - 'a'] = true;
            i++;
        }
        string ans = "";
        while (!st.empty()) {
            char c = st.top();
            ans += c;
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};