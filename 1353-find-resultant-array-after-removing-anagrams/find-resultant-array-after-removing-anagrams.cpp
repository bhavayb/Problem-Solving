class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;
        int n  = words.size();
        bool flag = true;
        vector<string> dummy;
        for(int i =0; i< n; i++){
            string s = words[i];
            sort(s.begin(), s.end());
            dummy.push_back(s);
        }
        ans.push_back(words[0]);
        for (int i = 1; i < n; i++) {
            if (dummy[i] != dummy[i-1]) {
                ans.push_back(words[i]);
            };
        }
        return ans;
    }
};