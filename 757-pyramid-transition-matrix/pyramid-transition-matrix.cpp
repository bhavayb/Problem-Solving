class Solution {
    private:
    bool helper(int ind,string temp,string &s,
    map<pair<char,char>,vector<char>>&hmap,unordered_map<string,bool>&memo)
    {       
        if(s.size() == 1)
        return true;

        if(ind == s.size()-1){
        if(memo.count(temp))
        return memo[temp];

        return memo[temp]=helper(0,"",temp,hmap,memo);
        }

        int take=false;
        if(hmap.count({s[ind],s[ind+1]})){
            for(auto &it : hmap[{s[ind],s[ind+1]}]){

                bool res=helper(ind+1,temp+it,s,hmap,memo);
                if(res)
                return memo[temp]=true;

                take|=res;
            }
        }
        return memo[temp]=take;
    }
public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        map<pair<char,char>,vector<char>>hmap;

        for(auto &it : allowed){
            hmap[{it[0],it[1]}].push_back(it[2]);
        }
        unordered_map<string,bool>memo;
        return helper(0,"",bottom,hmap,memo);
    }
};