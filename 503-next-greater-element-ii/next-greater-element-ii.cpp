class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for(int i = 2*n - 1; i >= 0; i--) {
            int temp = nums[i%n]; 
            while(!st.empty() && st.top() <= temp) {
                st.pop();
            }
            if( i < n){
                if(st.empty()) {
                    nums[i%n] = -1;
                } else {
                    nums[i%n] = st.top();
                }
            }
            
            st.push(temp);
        }

        return nums;
    }
};