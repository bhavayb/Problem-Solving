class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {
                st.push(i);
            }

            else if (s[i] == ')') {
                int ind = st.top();
                st.pop();

                int left = ind + 1;
                int right = i - 1;

                while (left < right) {
                    swap(s[left], s[right]);
                    left++;
                    right--;
                }
            }
        }

        string ans = "";

        for (char c : s) {
            if (c != '(' && c != ')') {
                ans += c;
            }
        }

        return ans;
    }
};