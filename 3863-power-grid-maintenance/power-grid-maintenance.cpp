class Solution {
public:

    void DFS(int node,int id,vector<int>&components,vector<bool>&visited,unordered_map<int,set<int>>&mp,unordered_map<int,vector<int>>&grid)
    {
        components[node]=id;
        visited[node]=true;
        mp[id].insert(node);
        for(auto &it:grid[node])
        {
            if(!visited[it])
            {
                DFS(it,id,components,visited,mp,grid);
            }
        }
    }

    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int,vector<int>>grid;
        for(auto &it:connections)
        {
            int u=it[0];
            int v=it[1];

            grid[u].push_back(v);
            grid[v].push_back(u);
        }

        vector<int>components(c+1);
        vector<bool>visited(c+1,false);
        unordered_map<int,set<int>>mp;
        for(int i=1;i<=c;i++)
        {
            if(!visited[i])
            {
                int id=i;
                DFS(i,id,components,visited,mp,grid);
            }
        }
        vector<int>result;
        for(auto &it:queries)
        {
            int status=it[0];
            int node=it[1];

            int id=components[node];
            if(status==1)
            {
                if(mp[id].find(node)!=mp[id].end())
                {
                    result.push_back(node);
                }
                else
                {
                    if(mp[id].empty())
                    {
                        result.push_back(-1);
                    }
                    else
                    {
                        result.push_back(*mp[id].begin());
                    }
                }
            }
            else if(status==2)
            {
                if(mp[id].find(node)!=mp[id].end())
                {
                    mp[id].erase(node);
                }
            }
        }
        return result;
    }
};