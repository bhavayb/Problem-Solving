

class Solution {
public:
    char findKthBit(int n, int k) {
        
        string s1 = "0"; 
        
        for (int i = 2; i <= n; i++)
        {
            string temp = s1;
            int len = temp.length();
            
            for(int j = 0; j < len; j++)
            {
                if (temp[j] == '0')
                    temp[j] = '1';
                else
                    temp[j] = '0';
            }

            reverse(temp.begin(), temp.end());
            
            s1 = s1 + '1' + temp;
        }

        return s1[k - 1];
    }
};