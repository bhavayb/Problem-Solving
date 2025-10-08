class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        for(int i = 0; i< spells.size(); i++){
            int count = 0;
            int low = 0; int high = potions.size()-1;
            while(low <= high){
                int mid = low + (high-low)/2;
                if((long long) spells[i]*potions[mid] >= success){
                    count += high - mid +1;
                    high = mid - 1;
                }else{
                    low = mid+1;
                }
            }
            spells[i] = count;
        }
        return spells;
    }
};