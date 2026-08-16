class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        int n = s.size();
        bool pos = true;
        int i = 0;
        while(i < n && s[i] == ' ') i++;
        if(i < n && s[i]=='-') {
            pos = false;
            i++;
        }else if(i < n && s[i] == '+') i++;
        for(int j = i; j < n; j++){
            if(s[j] < '0' || s[j] >'9') break;
            ans = ans*10 + s[j] - '0';
            if(ans >= INT_MAX && pos == true) return INT_MAX;
            else if(pos == false && ans >= (long long)INT_MAX+1) return INT_MIN;
        }
        if(pos) return ans;
        else return -ans;
    }
};