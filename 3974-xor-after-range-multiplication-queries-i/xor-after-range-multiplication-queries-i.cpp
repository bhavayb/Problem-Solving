class Solution {
    int MOD = 1e9 + 7;
    void func(vector<int> &nums, vector<int>& query){
        int i = query[0];
        int j = query[1];
        int k = query[2];
        int v = query[3];
        while(i <= j && i <= nums.size()){
            nums[i] = (1LL *nums[i] * v) % MOD;
            i+= k;
        }
    }
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(int i = 0; i < queries.size(); i++){
            func(nums, queries[i]);
        }
        int result = 0;
        for (int x : nums) {
            result ^= x;
        }
        return result;
    }
};