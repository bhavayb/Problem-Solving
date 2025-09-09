class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int mod=1e9+7;
       vector<long long> ad(n+2,0);
       vector<long long> dead(n+2,0);
        long long curr=0;
        long long total=1;
        int i=1;
        ad[delay+1]=1;
        if(forget+1<=n)
        dead[forget+1]=1;

        while(i<=n){
            curr=(curr+ad[i]-dead[i]+mod)%mod;
           
           total=(total-dead[i]+curr+mod)%mod;

            

            if(i+delay<=n && curr!=0)
            ad[i+delay]=(curr)%mod;

            if(i+forget<=n && curr!=0){
                dead[i+forget]=(curr)%mod;
            }
            
        i++;
        }

        return total;
    }
};