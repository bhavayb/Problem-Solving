class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n];

        // adjlist
        for(int i =0; i < isConnected.size(); i++){
            for(int j = 0; j< isConnected[0].size(); j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                }
            }
        }

        vector<int> vis(isConnected.size(), 0);
        int cnt = 0;
        queue<int> q;
        for(int i = 0; i < vis.size(); i++){
            if(vis[i] != 1){
                cnt++;
                q.push(i);
                vis[i] = 1;
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int j = 0;  j< adj[node].size(); j++){
                        if(vis[adj[node][j]] == 0){
                            q.push(adj[node][j]);
                            vis[adj[node][j]] = 1;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};