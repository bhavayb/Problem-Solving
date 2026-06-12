#include <vector>
#include <cmath>

using namespace std;

class Solution {
    vector<vector<int>> adj;   
    vector<int> depth;        
    vector<vector<int>> up;     

    void dfs(int node, int p, int d) {
        depth[node] = d;         
        up[node][0] = p;         
        for (int i = 1; i < 18; ++i) {
            if (up[node][i - 1] != -1)
                up[node][i] = up[up[node][i - 1]][i - 1];
            else
                up[node][i] = -1;
        }

        for (int child : adj[node]) {
            if (child != p) {
                dfs(child, node, d + 1);
            }
        }
    }
    int getLCA(int u, int v) {

        if (depth[u] < depth[v])
            swap(u, v);

        for (int i = 17; i >= 0; --i) {
            if ((depth[u] - depth[v]) & (1 << i)) {
                u = up[u][i];
            }
        }

        if (u == v)
            return u;
        for (int i = 17; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges,
                                  vector<vector<int>>& queries) {

        int n = edges.size() + 1;
        int MOD = 1e9 + 7;

        adj.resize(n + 1);
        depth.resize(n + 1);

        up.assign(n + 1, vector<int>(18, -1));
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(1, -1, 0);

        vector<int> pow2(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        }

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {

            int u = q[0];
            int v = q[1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            int lca = getLCA(u, v);
            int pathLength = depth[u] + depth[v] - 2 * depth[lca];

            ans.push_back(pow2[pathLength - 1]);
        }

        return ans;
    }
};