class Solution {
public:
    int minFlips(string s) {
        int n = s.size();

        int i = 0;
        int j = 0;
        
        int odd0 = 0;
        int odd1 = 0;
        int even0 = 0;
        int even1 = 0;
        while(j < n){
            if(j % 2 == 0){
                if(s[j] == '1') even1++;
                else even0++;
            }
            else{
                if(s[j] == '1') odd1++;
                else odd0++;
            }
            j++;
        }
        int ans = min(odd1 + even0, odd0 + even1);
        if(ans == 0 || n % 2 == 0) return ans;
        while(i < n){
            s[i] == '1' ? even1-- : even0--;
            
            swap(odd0, even0);
            swap(odd1, even1);
            
            s[i] == '1' ? even1++ : even0++;

            i++;
            ans = min(ans, min(odd1 + even0, odd0 + even1));
        }
        return ans;
    }
};