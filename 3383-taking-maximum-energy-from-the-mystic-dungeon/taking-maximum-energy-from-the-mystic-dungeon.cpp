class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        // vector<int> ans = energy;
        int n= energy.size();
        for(int i = n - k-1; i>= 0; i-- ){
            energy[i] += energy[i+k];
        }
        int maxi = energy[0];
        for(int i = 0; i <n; i++){
            maxi =  max(energy[i], maxi);
        }
        return maxi;
    }
};