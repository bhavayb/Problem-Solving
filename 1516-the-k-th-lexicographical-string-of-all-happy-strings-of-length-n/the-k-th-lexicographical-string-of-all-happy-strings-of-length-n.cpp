class Solution {
public:
    vector<string> col;
    string getHappyString(int n, int k) {
        string s = "";
        col.reserve(105); 
        helper(n, k, s);
        return col.size() < k ? "" : col[k-1];
    }
private:
    void helper(int n, int k, string& s){
        if(s.size() == n)
        {
            col.push_back(s);
            return;
        }
        for(int i = 'a'; i <= 'c' && col.size() < k; ++i)
        {
            if(!s.empty() && s.back() == i) continue;
            
            s += i;
            helper(n, k, s);
            s.pop_back();
        }
    }
};