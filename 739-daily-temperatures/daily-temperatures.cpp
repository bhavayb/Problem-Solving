class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();
        st.push({temperatures[n-1], n-1});
        vector<int> answer(n, 0);
        for(int i = n - 2; i >= 0 ; i--){
            int temp = temperatures[i];
            while(!st.empty()){
                int nexttemp = st.top().first;
                int ind = st.top().second;
                if(temp < nexttemp){
                    answer[i] = ind-i;
                    break;
                }
                else st.pop();
            }
            st.push({temperatures[i], i});
        }
        return answer;
    }
};