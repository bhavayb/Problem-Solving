class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string, int>> q;
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> vis;

        if(dead.find("0000") != dead.end()) return -1;
        q.push({"0000", 0});
        vis.insert("0000");

        while (!q.empty()) {
            auto [cur, steps] = q.front();
            q.pop();

            if (cur == target)
                return steps;

            for (int i = 0; i < 4; i++) {

                string next = cur;

                next[i] = (cur[i] == '9') ? '0' : cur[i] + 1;
                if (!dead.count(next) && !vis.count(next)) {
                    vis.insert(next);
                    q.push({next, steps + 1});
                }

                next = cur;
                next[i] = (cur[i] == '0') ? '9' : cur[i] - 1;
                if (!dead.count(next) && !vis.count(next)) {
                    vis.insert(next);
                    q.push({next, steps + 1});
                }
            }
        }
        return -1;
    }
};

    // queue<pair<string,int>> q;
    // unordered_set<string> dead(deadends.begin(), deadends.end());
    // unordered_set<string> vis;

    // q.push({"0000",0});
    // vis.insert("0000");

    // while(!q.empty()){
    //     auto [cur,steps]=q.front();
    //     q.pop();

    //     if(cur==target) return steps;

    //     for(int i=0;i<4;i++){

    //         string next=cur;

    //         next[i]=(cur[i]=='9')?'0':cur[i]+1;
    //         if(!dead.count(next) && !vis.count(next)){
    //             vis.insert(next);
    //             q.push({next,steps+1});
    //         }

    //         next=cur;
    //         next[i]=(cur[i]=='0')?'9':cur[i]-1;
    //         if(!dead.count(next) && !vis.count(next)){
    //             vis.insert(next);
    //             q.push({next,steps+1});
    //         }
    //     }
    // }