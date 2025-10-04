class Solution {
public:
    int maxArea(vector<int>& height) {
        int low = 0;
        int high = height.size()-1;
        long long maxwater = 0;
        while(low < high){
            if(height[low] <= height[high]){
                long long mini = min(height[low], height[high])* (high-low) ;
                maxwater = max(maxwater,mini);
                low++;
            }else{
                long long mini = min(height[low], height[high])* (high-low) ;
                maxwater = max(maxwater, mini);
                high--;
            }
        }
        return maxwater;
    }
};