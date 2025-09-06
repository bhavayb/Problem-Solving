class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long ans=0;


        for (auto it:queries){
             int low=it[0];
             int high=it[1];

              long long curr=1;
              vector<int>mov(17,0);
               int turn=0;
               while(curr<=high){ 
              //cout<<low<<" "<<curr<<endl;
                   if (low<curr){
                    //cout<<curr<<" "<<low<<endl;
                    mov[turn]=curr-low;
                    low=curr;

                   }
                   turn++;
                   curr=curr*1LL*4;

               }
               curr=curr/4;
               //cout<<low <<" "<<curr<<endl;
               mov[turn]=high-max((long long)low,curr)+1;


               for (int i=16;i>0;i--){
             //  cout<<i<<" "<<mov[i]<<endl;
                            ans += i*1LL*((mov[i])/2);
                           if (i!=1) mov[1]+= mov[i]%2;
                            if (mov[i]%2)mov[i-1]++;


               }
               if (mov[1]%2)ans++;


        }
        return ans;
    }
};