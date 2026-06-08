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
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mpp;
        int n = accounts.size();
        DisjointSet ds(n);
        for(int i = 0; i < n; i++){
            for(int j  = 1; j < accounts[i].size(); j++){
                string mail = accounts[i][j];
                if(mpp.find(mail) == mpp.end()){
                    mpp[mail] = i;
                }else{
                    ds.unionBySize(i, mpp[mail]);
                }
            }
        }
        vector<string> merged[n];
        for(auto it: mpp){
            string mail = it.first;
            int node = ds.findUParent(it.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i =0; i < n ; i++){
            if(merged[i].size() == 0) continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};