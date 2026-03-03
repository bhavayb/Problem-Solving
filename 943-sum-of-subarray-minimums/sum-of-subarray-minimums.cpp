class Solution {
    vector<int> nse(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i = arr.size()-1; i>= 0; i--){
            while(!st.empty() && arr[i] <= arr[st.top()]){
                st.pop();
            }
            if(st.empty()) ans[i] = arr.size();
            else ans[i] = st.top();

            st.push(i);
        }
        return ans;
    }

    vector<int> pse(vector<int> &arr){
        vector<int> ans(arr.size());
        stack<int> st;
        for(int i = 0; i < arr.size(); i++){
            while(!st.empty() && arr[i] < arr[st.top()]){
                st.pop();
            }
            if(st.empty()) ans[i] = -1;
            else ans[i] = st.top();

            st.push(i);
        }
        
        return ans;
    }


public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9+7;
        vector<int> nsearr = nse(arr);
        vector<int> psearr = pse(arr);
        long long ans = 0;
        for(int i= 0; i < nsearr.size(); i++){
            long long left = i - psearr[i];
            long long right = nsearr[i] - i;
            ans = (ans + (((arr[i] % mod) * left) % mod * right) % mod) % mod;
        }
        return ans;
    }
};