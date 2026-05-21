class Solution {
    unordered_map<string, int> func(vector<int>& arr){
        unordered_map<string, int> mpp;
        for(auto num: arr){
            string s = to_string(num);
            for(int i =0 ; i<= s.length(); i++){
                string x = s.substr(0, i);
                mpp[x]++;
            }
        }
        return mpp;
    }
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> mpp1 = func(arr1);
        unordered_map<string, int> mpp2 = func(arr2);
        int maxi = 0;
        for(auto it: mpp1){
            if(mpp2.find(it.first) != mpp2.end()){
                int x = it.first.length();
                maxi = max(x, maxi);
            }
        }
        return maxi;
    }
};