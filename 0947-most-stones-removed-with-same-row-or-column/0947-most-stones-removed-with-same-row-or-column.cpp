class DisjointSet{
public:
    vector<int> rank, parent, size;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        for(int i =0; i <= n; i++){
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
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0, maxcol = 0;
        for(auto it: stones){
            maxrow = max(maxrow, it[0]);
            maxcol = max(maxcol, it[1]);
        }
        DisjointSet ds(maxrow + maxcol+1);
        unordered_map<int, int> stonenodes;
        for(auto it: stones){
            int noderow = it[0], nodecol = it[1] + maxrow+1;
            ds.unionBySize(noderow, nodecol);
            stonenodes[noderow] = 1;
            stonenodes[nodecol] = 1;
        }

        int cnt = 0;
        for(auto it: stonenodes){
            if(ds.findUParent(it.first) == it.first) cnt++;
        }
        return stones.size() - cnt;
    }
};