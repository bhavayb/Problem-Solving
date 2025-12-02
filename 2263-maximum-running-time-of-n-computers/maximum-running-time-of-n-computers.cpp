class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        sort(batteries.begin(),batteries.end());
        int m = batteries.size();

        int i;
        long long total = 0;
        long long time  = 0;
        long long last = 0;
        for(i = 0; i<m; i++)
        {
            last = time;
            time = (total+(m-i)*(long long)batteries[i])/n;
            if (time < batteries[i]) 
                return total/(n-m+i);
            total += (long long)batteries[i];           
        }
        return time;
    }
};