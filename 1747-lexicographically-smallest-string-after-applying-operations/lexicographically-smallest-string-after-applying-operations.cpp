class Solution {
public:
  
   void rotatey(string &s,int b){
    reverse(s.begin(),s.end());
    reverse(s.begin(),s.begin()+b);
    reverse(s.begin()+b,s.end());
   }
    string findLexSmallestString(string s, int a, int b) {
        string ans=s;
        queue<string>q;
        unordered_set<string>vis;
        q.push(s);
        vis.insert(s);
        while(!q.empty()){
            string curr=q.front();
            q.pop();

            if(curr<ans)ans=curr;

            string temp=curr;

            for(int i=1;i<curr.size();i+=2){
               temp[i]=((temp[i]-'0'+a)%10)+'0';
            }
            if(!vis.count(temp)){
                vis.insert(temp);
                q.push(temp);
            }

           rotatey(curr,b);
            if(!vis.count(curr)){
                vis.insert(curr);
                q.push(curr);
            }
        }
        return ans;

    }
};