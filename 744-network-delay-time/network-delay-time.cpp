class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1, 1e9);
        vector<vector<pair<int,int>>> adj(n+1);
        for(auto it: times){
            int u = it[0];
            int v= it[1];
             int w = it[2];
             adj[u].push_back({v, w});
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            for(auto it: adj[node]){
                int adjnode = it.first;
                int wt  = it.second;
                if(dis + wt < dist[adjnode]){
                    dist[adjnode] = dis + wt;
                    pq.push({dist[adjnode], adjnode});
                }
                 
            }
        }
        int maxi  =  -1;
        for(int i = 1; i <= n; i++ ){
            if(dist[i] > maxi) maxi = dist[i];
        }
        return maxi == 1e9 ? -1: maxi;
    }
};