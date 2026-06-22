class Solution {
public:
    int countValidSubarrays(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                long long sum = pref[j + 1] - pref[i];

                int last = sum % 10;

                long long temp = sum;
                while (temp >= 10)
                    temp /= 10;

                int first = temp;

                if (first == x && last == x)
                    cnt++;
            }
        }

        return cnt;
    }
};