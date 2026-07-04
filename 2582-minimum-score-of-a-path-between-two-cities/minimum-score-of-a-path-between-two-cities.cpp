class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // for(int i = 0;i <roads.size(); i++){
        //     mini = min(mini, roads[i][2]);
        // }
        // return mini;
        vector<vector<int>> adj[n+1];
        for(int i = 0; i < roads.size(); i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int d = roads[i][2];
            adj[u].push_back({v,d});
            adj[v].push_back({u, d});
        }
        vector<bool> vis(n+1, false);
        int mini = INT_MAX;
        queue<pair<int,int>> q;
        q.push({1,INT_MAX});
        vis[1] = true;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dist = it.second;
            int node = it.first;
            for(auto it: adj[node]){
                int adjnode = it[0];
                int adjdist = it[1];
                mini = min(mini, adjdist);
                if(!vis[adjnode]){
                    q.push({adjnode, adjdist});
                    vis[adjnode] = true;
                }
            }
        }
        return mini;
    }
};