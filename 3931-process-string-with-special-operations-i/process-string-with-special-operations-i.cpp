class Solution {
public:
    string processStr(string s) {
        string result = "";
        for(auto it: s){
            if(it == '*' ){
                if(result != "") result = result.substr(0, result.length()-1);
            }else if(it == '#'){
                if(result != "") result += result;
            }else if(it == '%'){
                if(result != "") reverse(result.begin(), result.end());
            }else {
                result += it;
            }
        }
        return result;
    }
};