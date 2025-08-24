class Solution {
    private:
    int odd(int n){
        int i = 1;
        int sum = 0;
        int count = 1;
        while( count <= n){
            sum += i;
            count++;
            i = i+2;
        }
        return sum;
    }
    int even(int n){
        int i = 2;
        int sum = 0;
        int count = 1;
        while( count <= n){
            sum += i;
            count++;
            i = i+2;
        }
        return sum;
    }
public:
    int gcdOfOddEvenSums(int n) {
        int sumOfOdd = odd(n);
        int sumOfEven = even(n);
        
        return gcd(sumOfEven, sumOfOdd);
        // return sumOfEven;
    }
};