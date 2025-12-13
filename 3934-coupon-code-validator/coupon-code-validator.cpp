class Solution {
    bool validfunc(string code){
        if(code == "" || code == " ") return false; 
        for(int i = 0; i < code.length(); i++){
            if((code[i] <= 'z' && code[i] >= 'a') || (code[i] >= 'A' && code[i] <= 'Z') || (code[i] >= '0' && code[i] <= '9') || code[i] == '_'){
                continue;
            }else{
                return false;
            }
        }
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        map<string, vector<string>> ans;
        for(int i = 0 ; i < isActive.size(); i++){
            if(isActive[i] == false){
                continue;
            }else{
                if(businessLine[i] == "restaurant" || businessLine[i] == "grocery" || businessLine[i] =="pharmacy" ||businessLine[i] == "electronics" ){
                    if(validfunc(code[i]) == true){
                        ans[businessLine[i]].push_back(code[i]);
                    }
                }else{
                    continue;
                }
            }
        }
        vector<string> p;
        for(auto it: ans){
            if((it.second).size() > 1){
                sort((it.second).begin(), (it.second).end());
            }
            for(int i = 0; i < (it.second).size(); i++){
                p.push_back((it.second)[i]);
            }

        }
        return p;
    }
};