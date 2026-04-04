class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int n = encodedText.size();
        int lenOfstr = 0;
        int cols = n/rows;
        vector<vector<char>> text(rows, vector<char>(cols, ' '));
        int x = 0;
        int y = 0;
        for(int i = 0; i < n; i++){
            text[x][y] = encodedText[i];
            y++;
            if(y%cols == 0){
                x++; y = 0;
            }
        }
        y = 0;
        string originalText = "";
        int j = 0;
        while(y < cols){
            j = y;
            int i = 0;
            while(i < rows && j < cols){
                if(text[i][j] == ' ') originalText += ' ';
                if(text[i][j] != ' ') originalText += text[i][j];
                i++;
                j++;
            }
            y++;
        }
        originalText.erase(originalText.find_last_not_of(' ') + 1);
        return originalText;
        
    }
};