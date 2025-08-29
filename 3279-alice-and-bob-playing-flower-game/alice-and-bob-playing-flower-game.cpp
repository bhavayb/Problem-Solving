class Solution {
public:
    long long flowerGame(int n, int m) {
        long long evenN = 0, oddN = 0, evenM = 0, oddM = 0;
        long long count = 0;
        if(n%2 == 1 && m%2 == 0){
            evenN = (n-1)/2;
            oddN = evenN + 1;
            evenM = m/2;
            oddM = m/2;
            count = (evenN* oddM) + (oddN* evenM);
            return count;
        }
        else if(n%2 == 0 && m%2 == 0){
            evenN = n/2;
            oddN = n/2;
            evenM = m/2;
            oddM = m/2;
            count = (evenN* oddM) + (oddN* evenM);
            return count;
        }
        else if(n%2 == 0 && m%2 == 1){
            evenN = n/2;
            oddN = evenN;
            evenM = (m-1)/2;
            oddM = evenM+1;
            count = (evenN* oddM) + (oddN* evenM);
            return count;
        }
        else{
            evenN = (n-1)/2;
            oddN = evenN + 1;
            evenM = (m-1)/2;
            oddM = evenM + 1;
            count = (evenN* oddM) + (oddN* evenM);
            return count;
        }
    }
};