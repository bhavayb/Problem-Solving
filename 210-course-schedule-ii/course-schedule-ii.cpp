class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjlist(numCourses);
        for(int i = 0; i< prerequisites.size(); i++){
            int u = prerequisites[i][0];
            int v= prerequisites[i][1];
            adjlist[v].push_back(u);
        }
        vector<int> indegree(numCourses,0 );
        for(int i = 0; i < numCourses; i++){
            for(auto it: adjlist[i]){
                indegree[it]++;
            }
        }
        queue<int> q;
        for(int i = 0; i < indegree.size();i++){
            if(indegree[i] == 0) q.push(i);
        }
        vector<int> ans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i = 0; i < adjlist[node].size(); i++){
                indegree[adjlist[node][i]]--;
                if(indegree[adjlist[node][i]] == 0) q.push(adjlist[node][i]);
            }
        }
        if(ans.size() == numCourses){
            return ans;
        }else return {};
    }
};