class Solution{    
  public:    
    bool lemonadeChange(vector<int>& bills){
        int nooffive = 0;
        int nooften = 0;
        for(int i  =0; i < bills.size(); i++){
            if(bills[i] == 5) nooffive++;
            else if(bills[i] == 10){
                if(nooffive <= 0) return false;
                nooften++;
                nooffive--;
            }else{
                if(nooften > 0){
                    if(nooffive <= 0) return false;
                    nooffive--;
                    nooften--;
                }else{
                    if(nooffive >= 3){
                        nooffive = nooffive - 3;
                    }else return false;
                }
            }
        }
        return true;
    }
};