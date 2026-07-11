class Solution {
public:
    int numSplits(string s) {
        unordered_map<char,int> mpp;
        int n= s.length();
        vector<int> prefix(n);

        for(int i = 0; i < n; i++ ){
            mpp[s[i]]++;
            prefix[i] = mpp.size();
        }
        mpp.clear();
        int cnt = 0;
        for(int i = n-1; i>= 0; i--){
            mpp[s[i]]++;
            if( i > 0 && mpp.size() == prefix[i-1]) cnt++;
        }
        return cnt;
    }
};