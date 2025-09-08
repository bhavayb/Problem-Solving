class Solution {
private:
    bool hasZero(int num) {
        while (num > 0) {
            if (num % 10 == 0)
                return true;
            num /= 10;
        }
        return false;
    }

public:
    vector<int> getNoZeroIntegers(int n) {
        for (int i = 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i + j == n && !hasZero(i) && !hasZero(j)) {
                    return {i, j};
                }
            }
        }
        return {1,1};
    }
};