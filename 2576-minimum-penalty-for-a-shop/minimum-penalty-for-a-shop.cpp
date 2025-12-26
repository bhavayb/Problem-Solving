class Solution {
public:
    int bestClosingTime(string customers) {
        int ini = 0;
        for(int i = 0; i < customers.size(); i++){
            if(customers[i] == 'Y') ini++;
        }
        int mini = ini;
        int ans = 0;
        int i =1;
        while(i <= customers.size()){
            if(customers[i-1] == 'Y'){
                ini = ini - 1;
                if(mini > ini){
                    ans = i;
                    mini = ini;
                }
            }else{
                ini = ini +1;
                if(mini > ini){
                    ans = i;
                    mini = ini;
                }

            }
            i++;
        }
        return ans;
    }
};