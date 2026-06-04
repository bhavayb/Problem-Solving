class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        pair<int,int> source = {0,0};
        pair<int,int> destination = {n-1, m-1};
        if(grid[0][0] == 1) return -1;
        if(source.first == destination.first && source.second == destination.second) return 1;
        dist[source.first][source.second] = 0;
        q.push({0, {source.first, source.second}});
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            int dis = it.first; 
            int r = it.second.first;
            int c = it.second.second;
            for(int i = -1; i<= 1; i++){
                for(int j = -1; j <= 1; j++){
                    if(i != 0 || j != 0){
                        int newr = r + i;
                        int newc = c + j;
                        if(newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 0 && dis + 1 < dist[newr][newc]){
                            dist[newr][newc] = 1 + dis;
                            q.push({1+dis, {newr, newc}});
                        }
                    }
                }
            }
        }
        return dist[n-1][m-1] == 1e9 ? -1 : dist[n-1][m-1] +1;
    }
};