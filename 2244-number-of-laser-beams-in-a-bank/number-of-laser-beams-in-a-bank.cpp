class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        // int noOfNonZeroRows = 0;
        int sizeOfString = bank[0].length();
        string x;
        for(int i = 0; i< sizeOfString; i++){
            x += '0';
        }
        vector<int> noOfOnes;
        for(int i = 0; i < bank.size(); i++){
            if(bank[i] != x){
                int count = 0;
                for(int j = 0; j < bank[i].size(); j++){
                    if(bank[i][j] == '1') count++;
                }
                noOfOnes.push_back(count);
            }
        }
        if(noOfOnes.size() == 1 || noOfOnes.size() == 0) return 0;
        int laser = 0;
        for(int i = 0; i < noOfOnes.size()-1; i++){
            laser += noOfOnes[i]*noOfOnes[i+1];
        }
        return laser;
    }
};