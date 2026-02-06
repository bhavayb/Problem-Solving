class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, -1);
        // queue<int> q;
        for(int i = 0 ; i < V; i++){
            if(vis[i] == -1){
                vis[i] = 0;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int j = 0;  j < graph[node].size(); j++){
                        if(vis[graph[node][j]] == -1){
                            if(vis[node] == 1) vis[graph[node][j]] = 0;
                            else vis[graph[node][j]] = 1;

                            q.push(graph[node][j]);
                        }
                        else if(vis[graph[node][j]] == vis[node] ) return false;
                    }
                }
            }
        }
        return true;

    }
};