class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        map<int, int> mpp;
        for(int i = 0; i< friends.size(); i++){
            for(int  j = 0; j< order.size(); j++){
                if(order[j] == friends[i]){
                    mpp[j] = friends[i];
                    break;
                }
            }
        }
        vector<int> ans;
        for(auto item: mpp){
            ans.push_back(item.second);
        }
        return ans;
    }
};