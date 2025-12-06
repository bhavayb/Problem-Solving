class Solution {
public:
    string convert(string s, int numRows) {
        
        if (numRows == 1) return s;

        vector<vector<char>> zigzag(numRows, vector<char>(s.length(), ' '));
        
        int i = 1, k = 0; 
        zigzag[0][0] = s[0];

        while(i < s.length()){
            int j = 1;
            while(j < numRows && i < s.length()){
                zigzag[j][k] = s[i++];
                j++;
            }
            j = j - 2;

            while(j >= 0 && i < s.length()){
                k++;
                zigzag[j][k] = s[i++];
                j--;
            }
        }
        string ans = "";
        for(int r = 0; r < numRows; r++){
            for(int c = 0; c < zigzag[0].size(); c++){
                if(zigzag[r][c] != ' ')
                    ans += zigzag[r][c];
            }
        }

        return ans;
    }
};

