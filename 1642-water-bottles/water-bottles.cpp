class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drinkBottles = 0;
        int empty = 0;
        while(numBottles > 0){
            drinkBottles += numBottles;        
            empty += numBottles; 
            numBottles = empty / numExchange;  
            empty = empty % numExchange; 
        }
        return drinkBottles;
    }
};
