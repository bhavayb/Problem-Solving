class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
       for(char ch: str){
            if(!st.empty() && ((st.top() == '(' && ch == ')') || (st.top() == '{' && ch == '}') || (st.top() == '[' && ch == ']') )){
                st.pop();
            }
            else{
                st.push(ch);
            }
       }
       return st.empty();
    }
};