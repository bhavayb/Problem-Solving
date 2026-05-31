class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long ans = mass;
        for(auto asteroid : asteroids){
            if(ans < asteroid) return false;
            else ans += asteroid;
        }
        return true;
    }
};