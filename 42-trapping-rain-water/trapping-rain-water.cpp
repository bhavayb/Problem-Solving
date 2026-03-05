class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size()), suffix(height.size());
        for(int i =0; i < height.size(); i++){
            if(i == 0) prefix[i] = height[i];
            else{
                prefix[i] = max(prefix[i-1], height[i]);
            }
        }
        for(int i =height.size()-1; i >= 0; i--){
            if(i == height.size()-1) suffix[i] = height[i];
            else{
                suffix[i] = max(suffix[i+1], height[i]);
            }
        }
        int total = 0;
        for(int i =0; i< height.size(); i++){
            if(height[i] < min(prefix[i], suffix[i])){
                total += min(prefix[i], suffix[i]) - height[i];
            }
        }
        return total;
    }
};