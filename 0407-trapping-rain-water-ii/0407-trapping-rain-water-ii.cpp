class Solution {
public:

    int dir[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};

    int trapRainWater(vector<vector<int>>& hm) {
        
        int n = hm.size(); 
        int m = hm[0].size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
        
        vector<vector<int>>visited(n,vector<int>(m,0)); 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || i==n-1 || j==0 || j==m-1){ 
                    minHeap.push({hm[i][j],{i,j}}); 
                    visited[i][j] = 1; 
                }
            }
        }
        int ans = 0;
        while(!minHeap.empty()){
            auto t = minHeap.top();
            minHeap.pop();
            int curr_ht = t.first;
            int x = t.second.first;
            int y = t.second.second;
            for(int k=0;k<4;k++){
                int newx = x + dir[k][0];
                int newy = y + dir[k][1];
                if(newx>=n || newy>=m || newy<0 || newx<0 || visited[newx][newy]) continue; 
                int newHt = hm[newx][newy];
                ans += max(0,curr_ht-newHt); 
                minHeap.push({max(curr_ht, newHt), {newx, newy}});
                visited[newx][newy] = 1; 
            }
        }

        return ans;
    }
};