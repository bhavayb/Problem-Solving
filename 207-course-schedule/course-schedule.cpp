class Solution {
    bool dfs(int node, vector<vector<int>>& adjlist, vector<int>& vis, vector<int>& pathvis, int numCourses){
        vis[node] = 1;
        pathvis[node] = 1;
        for(int i = 0; i < adjlist[node].size(); i++){
            if( pathvis[adjlist[node][i]] == 1) return true;
            else if(!vis[adjlist[node][i]]){
                if(dfs(adjlist[node][i], adjlist, vis, pathvis, numCourses)) return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses+1);
        for(int i =0; i < prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adjlist[u].push_back(v);
        }
        vector<int> vis(numCourses+1, 0);
        vector<int> pathvis(numCourses+1, 0);
        for(int i =0; i< vis.size(); i++){
            if(vis[i] == 0){
                if(dfs(i, adjlist, vis, pathvis, numCourses) == true){
                    return false;
                }
            }
        }
        return true;
    }
};