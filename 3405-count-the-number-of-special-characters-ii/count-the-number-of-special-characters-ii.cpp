class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> mpp1, mpp2;
        for(int i = 0; i< word.length(); i++){
            if(word[i] >= 'a' && word[i] <= 'z'){
                mpp1[word[i]] = i;
            }
            else{
                if(mpp2.find(word[i]) == mpp2.end()){
                    mpp2[word[i]] = i;
                }
            }
        }

        int ans = 0;
        for(auto it:mpp1){
            char x = it.first - 32;
            if(mpp2.find(x)!= mpp2.end() && it.second < mpp2[x]){
                ans++;
            }
        }
        return ans;
    }
};