class Solution {
public:
    int maximumProduct(vector<int>& A) {
        int n = A.size();
        for (int i = 0; i < 2; i++) {                 
            int k = i;
            for (int j = i + 1; j < n; j++)
                if (A[j] < A[k]) k = j;                 
            swap(A[i], A[k]);                           
        }
        for (int i = n - 1; i >= max(0, n - 3); i--) {  
            int k = i;
            for (int j = 0; j < i; j++)
                if (A[j] > A[k]) k = j;                 
            swap(A[i], A[k]);                           
        }

        return max(
            A.back() * A[n - 2] * A[n - 3],
            A.back() * A.front() * A[1]
        );
    }
};