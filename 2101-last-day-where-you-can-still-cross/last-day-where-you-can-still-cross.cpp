class Solution {
public:
    vector<int> rank, parent;

    vector<pair<int,int>> dirs = {
        {0,1},{0,-1},{-1,0},{1,0}
    };
    int findParent(int node){
        if(parent[node] == node) 
            return node;
        return parent[node] = findParent(parent[node]);
    }   

    void unite(int x,int y){
        x = findParent(x);
        y = findParent(y);

        if(x == y) return;

        if(rank[x] > rank[y]) 
            parent[y] = x;
        else if(rank[y] > rank[x]) 
            parent[x] = y;
        else{
            parent[x] = y;
            rank[y]++;
        }
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {

        int n = row * col;
        rank.resize(n + 2, 0);
        parent.resize(n + 2);

        for(int i = 0; i <= n + 1; i++){
            parent[i] = i;
        }
        int top = n;
        int bottom = n + 1;

        vector<vector<int>> grid(row, vector<int>(col, 0));

        for(int i = n - 1; i >= 0; i--){

            int r = cells[i][0] - 1;
            int c = cells[i][1] - 1;
            grid[r][c] = 1;

            int id = r * col + c;
            if(r == 0){
                unite(id, top);
            }
            if(r == row - 1){
                unite(id, bottom);
            }
            for(auto [dr, dc] : dirs){
                int nr = r + dr;
                int nc = c + dc;
                if(nr >= 0 && nc >= 0 && nr < row && nc < col && grid[nr][nc]){
                    unite(id, nr * col + nc);
                }
            }
            if(findParent(top) == findParent(bottom)){
                return i;  
            }
        }
        return 0;
    }
};