class Solution {
public:
    vector<int> nextGreaterElements(vector<int> &arr) {
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n,-1);
        for(int i = n-1; i >= 0; i--){
            st.push(arr[i]);
        }
        for(int i = n-1; i >= 0 ; i--){
            int val = arr[i];
            while(!st.empty()){
                if(val < st.top()){
                    ans[i] = st.top();
                    break;
                }else st.pop();
            }
            st.push(val);
        }
        return ans;
    }
};