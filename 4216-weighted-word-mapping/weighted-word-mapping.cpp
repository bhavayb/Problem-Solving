class Solution {
    char weight(string s, vector<int>& weights ){
        int sum =0;
        for(int i= 0; i < s.length(); i++){
            int ind = s[i] - 'a';
            sum += weights[ind];
        }
        sum =  sum % 26;
        sum = 25 - sum;
        return (char)(sum + 'a');
    }
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(auto s : words){
            ans += weight(s, weights);
        }
        return ans;
    }
};