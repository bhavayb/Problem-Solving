class Solution {
    bool checkhorizontal(vector<vector<int>>& grid, int m, int n){
        vector<long long> row(m, 0), prefix(m, 0);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                row[i] += grid[i][j];
            }
        }

        prefix[0] = row[0];
        for(int i = 1; i < m; i++){
            prefix[i] = prefix[i-1] + row[i];
        }

        long long total = prefix[m-1];
        for(int i = 0; i < m-1; i++){
            if(prefix[i] == total - prefix[i]) return true;
        }

        return false;
    }

    bool checkvertical(vector<vector<int>>& grid, int m, int n){
        vector<long long> col(n, 0), prefix(n, 0);

        for(int j = 0; j < n; j++){
            for(int i = 0; i < m; i++){
                col[j] += grid[i][j];
            }
        }

        prefix[0] = col[0];
        for(int j = 1; j < n; j++){
            prefix[j] = prefix[j-1] + col[j];
        }

        long long total = prefix[n-1];
        for(int j = 0; j < n-1; j++){
            if(prefix[j] == total - prefix[j]) return true;
        }

        return false;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if(checkhorizontal(grid, m, n)) return true;
        if(checkvertical(grid, m, n)) return true;
        return false;
    }
};