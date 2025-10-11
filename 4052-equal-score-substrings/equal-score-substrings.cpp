class Solution {
    private:
    int func(string s){
        int sum = 0;
        for(int i = 0; i< s.length(); i++){
            sum += (s[i] - 96);
        }
        return sum;
    }
public:
    bool scoreBalance(string s) {
        if(s.length() == 2 && s[0] == s[1]) return true;
    
        for(int i = 1; i< s.length()-1; i++){
            if(func(s.substr(0, i+1)) == func(s.substr(i+1, s.length() - i ))){
                return true;
            }
        }
        return false;
    }
};