class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = letters[0];
        for(auto ch: letters){
            if(ch > target){
                return ch;
            }
        }
        return ans;
    }
};