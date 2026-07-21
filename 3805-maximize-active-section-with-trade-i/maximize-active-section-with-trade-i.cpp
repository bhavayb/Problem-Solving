class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        s = "1" + s + "1";
        vector<pair<char, int>> blocks;
        for (char c : s) {
    if (blocks.empty() || blocks.back().first != c) {
        blocks.push_back({c, 1});
    } else {
        blocks.back().second++;
    }
}

        int totalOnes = 0;

        for (int i = 0; i < blocks.size(); i++) {
            if (blocks[i].first == '1'){
                totalOnes += blocks[i].second;
            }
        }

        totalOnes -= 2;
        int ans = totalOnes;
        for (int i = 1; i + 1 < blocks.size(); i++) {
            if (blocks[i].first == '1' && blocks[i - 1].first == '0' && blocks[i + 1].first == '0') {
                ans = max(ans, totalOnes + blocks[i - 1].second + blocks[i + 1].second);
            }
        }

        return ans;
    }
};