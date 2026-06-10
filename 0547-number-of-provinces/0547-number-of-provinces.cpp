class Solution {
public:
    int findCircleNum(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> adjlist[V];
        for(int i = 0; i < V; i++){
            for(int j = 0; j < V; j++){
                if(adj[i][j] == 1){
                    int u = i;
                    int v = j;
                    adjlist[u].push_back(v);
                }
            }
        }
        queue<int> q;
        int cnt= 0;
        vector<int> vis(V);
        for(int i =0; i < V; i++){
            if(!vis[i]){
                cnt++;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto it: adjlist[node]){
                        if(!vis[it]){
                            q.push(it);
                            vis[it] = 1;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};