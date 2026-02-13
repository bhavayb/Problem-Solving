class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>> adjRev(V);
        for(int i = 0; i < V; i++){
            for(auto it: graph[i]){
                adjRev[it].push_back(i);
            }
        }
        vector<int> ans;
        vector<int> indegree(V,0);
        for(int  i= 0; i< V; i++){
            for(auto it: adjRev[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0; i< V; i++){
            if(indegree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i = 0; i < adjRev[node].size(); i++){
                indegree[adjRev[node][i]]--;
                if(indegree[adjRev[node][i]] == 0) {
                    q.push(adjRev[node][i]);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};