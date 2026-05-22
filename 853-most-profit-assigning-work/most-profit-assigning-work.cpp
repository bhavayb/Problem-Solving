class Solution {
    private:
    int findJob(vector<pair<int,int>>& jobs, int ability) {
        int low = 0;
        int high = jobs.size() - 1;
        int ans = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (jobs[mid].first <= ability) {
                ans = mid;          
                low = mid + 1;      
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> vec;
        for(int i = 0; i < difficulty.size(); i++){
            vec.push_back({difficulty[i], profit[i]});
        }

        sort(vec.begin(), vec.end());
        vector<int> prefixMax(vec.size());
        prefixMax[0] = vec[0].second;

        for (int i = 1; i < vec.size(); i++) {
            prefixMax[i] = max(prefixMax[i - 1], vec[i].second);
        }

        int maxprofit = 0;
        for(int i =0; i< worker.size(); i++){
            int ind = findJob(vec, worker[i]); 
            if (ind != -1) {
                maxprofit += prefixMax[ind];
            }
        }
        
        return maxprofit;
    }
};