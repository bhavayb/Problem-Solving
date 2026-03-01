class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        for(int i =0; i < asteroids.size(); i++){
            bool done = false;
            while(!st.empty() && asteroids[i] < 0){
                if(abs(asteroids[i]) > st.top()) st.pop();
                else if(abs(asteroids[i]) == st.top()){
                    st.pop();
                    done = true;
                    break;
                }
                else break;
            }
            if(done == false && st.empty() && asteroids[i] < 0){
                ans.push_back(asteroids[i]);
            }
            
            if(asteroids[i] >= 0) st.push(asteroids[i]); 
        }
    
        stack<int> reversed;
        while (!st.empty()) {
            reversed.push(st.top());
            st.pop();
        }
        while(!reversed.empty()){
            ans.push_back(reversed.top());
            reversed.pop();    
        }
        return ans;
        // while(!st.empty() && asteroids[i] < 0){
        //     if()
        // }
    }
};