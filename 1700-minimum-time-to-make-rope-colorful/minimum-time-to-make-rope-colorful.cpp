class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int time = 0;
        int n = colors.size();
        int currtime = neededTime[0];
        char currchar = colors[0];
        for(int i = 1; i < n; i++){
            if(colors[i] == currchar){
                time += min(currtime, neededTime[i]);
                currtime = max(currtime, neededTime[i]);
            }else{
                currchar = colors[i];
                currtime = neededTime[i];
            }
        }
        return time;
    }
};