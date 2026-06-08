class DisjointSet{
public:
    vector<int> rank, parent, size;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i =0; i < n; i++){
            parent[i] = i;
        }
        size.resize(n+1, 1);
    }
    int findUParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ultp_u = findUParent(u);
        int ultp_v = findUParent(v);

        if(ultp_u == ultp_v) return;

        if(rank[ultp_u] < rank[ultp_v]){
            parent[ultp_u] = ultp_v;
        }
        else if(rank[ultp_v] < rank[ultp_u]){
            parent[ultp_v] = ultp_u;
        }
        else{
            parent[ultp_v] = ultp_u;
            rank[ultp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ultp_u = findUParent(u);
        int ultp_v = findUParent(v);

        if(ultp_u == ultp_v) return;

        if(size[ultp_u] < size[ultp_v]){
            parent[ultp_u] = ultp_v;
            size[ultp_v] += size[ultp_u];
        }
        else{
            parent[ultp_v] = ultp_u;
            size[ultp_u] += size[ultp_v];
        }
    }
};

class Solution {
    bool isValid(int row, int col, int n){
        return (row < n && col < n && row >= 0 && col >= 0);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);

        for(int row = 0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 0) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,-1,0,1};
                for(int ind = 0; ind < 4; ind++){
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if(isValid(newr, newc, n) && grid[newr][newc] == 1){
                        int nodeno = row*n+col;
                        int adjnodeno = newr*n + newc;
                        ds.unionBySize(nodeno, adjnodeno);
                    }
                }
            }
        }

        int mx = 0;
        for(int row =0; row < n; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == 1) continue;
                int dr[] = {-1,0,1,0};
                int dc[] = {0,1,0,-1};

                set<int> component;
                for(int ind = 0; ind < 4; ind++){
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if(isValid(newr, newc, n)){
                        if(grid[newr][newc] == 1){
                            component.insert(ds.findUParent(newr*n + newc));
                        }
                    }
                }

                int size = 1;
                for(auto it: component){
                    size += ds.size[it];
                }
                mx = max(size, mx);
            }
        }
        for(int i = 0; i < n*n; i++){
            mx = max(mx, ds.size[ds.findUParent(i)]);
        }
        return mx;

    }
};