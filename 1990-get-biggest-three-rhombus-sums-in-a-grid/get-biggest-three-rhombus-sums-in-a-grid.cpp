class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> res;
        int size=min(grid.size(),grid[0].size());
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                for(int k=2;k<=ceil(size/2.0);k++)
                {
                    if(j-k+1 < 0 || j+k-1 >= grid[0].size() || i+2*(k-1) >= grid.size())
                    {
                        break;
                    }
                    int sum=grid[i][j],i1=i,j1=j;
                    i1++;j1--;
                    int c=1;
                    while(c < (k-1))
                    {
                        sum+=grid[i1][j1];
                        i1++;
                        j1--;
                        c++;
                    }
                    sum+=grid[i1][j1];
                    i1++;
                    j1++;
                    c=1;
                    while(c < (k-1))
                    {
                        sum+=grid[i1][j1];
                        i1++;
                        j1++;
                        c++;
                    }
                    sum+=grid[i1][j1];
                    i1--;
                    j1++;
                    c=1;
                    while(c<(k-1))
                    {
                        sum+=grid[i1][j1];
                        i1--;
                        j1++;
                        c++;
                    }
                    sum+=grid[i1][j1];
                    i1--;
                    j1--;
                    c=1;
                    while(c < (k-1))
                    {
                        sum+=grid[i1][j1];
                        i1--;
                        j1--;
                        c++;
                    }
                    res.push_back(sum);
                }
                res.push_back(grid[i][j]);
            }
        }
        sort(res.begin(),res.end(),greater<>());
        vector<int> v;
        int c=1;
        v.push_back(res[0]);
        for(int i=1;i<res.size() && c < 3;i++)
        {
            if(res[i] != res[i-1])
            {
                v.push_back(res[i]);
                c++;
            }
        }
        return v;
    }
};