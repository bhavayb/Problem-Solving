class Solution {
public:
    bool doesAliceWin(string s) {
        int count = 0;
        for(int i = 0; i< s.length(); i++){
            if(s[i] == 'a' || s[i] == 'u' || s[i] == 'i' || s[i] == 'o' || s[i] == 'e'){
                count++;
            }
        }
        if(count == 0){
            return false;
        }
        // int c = 0; 
        // int step = 1;
        // while(c <= count){
        //     if(step %2 != 0){
        //         if(count - c >= 1){
        //             step++;
        //             c++;
        //         }else{
        //             return false;
        //         }
        //     }else{
        //         if(count - c >=2){
        //             step++;
        //             c= c+2;
        //         }else{
        //             return true;
        //         }
        //     }
        // }
        return true;
    }
};