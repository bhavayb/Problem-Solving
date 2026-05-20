class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n, 0);
        unordered_map<int,int> mpp1, mpp2;

        for(int i = 0; i < n; i++){
            mpp1[A[i]] = i;
            mpp2[B[i]] = i;
        }

        if(A[0] == B[0]) C[0] = 1;

        for(int i = 1; i < n; i++){
            if(A[i] == B[i]){
                C[i] = C[i-1] + 1;
                continue;
            }
            C[i] = C[i-1];
            if(mpp2[A[i]] <= i) C[i] += 1;
            if(mpp1[B[i]] <= i) C[i]+=1;
        }
        return C;
    }
};