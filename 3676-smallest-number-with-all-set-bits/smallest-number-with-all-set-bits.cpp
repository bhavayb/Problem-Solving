class Solution {
public:
    int smallestNumber(int n) {
        vector<int> powerOfTwo = {1, 2, 4 , 8 , 16, 32, 64, 128, 256, 512, 1024};
        for(int i = 0 ; i < powerOfTwo.size(); i++ ){
            if(powerOfTwo[i] == n) return n*2 - 1;
            if(n <= powerOfTwo[i] && n >= powerOfTwo[i-1] && i > 0){
                return powerOfTwo[i] - 1;
            }
        }
        return 0;
    }
};