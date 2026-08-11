class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        // suf[i] = longest suffix of word2 that can be matched
        // as a subsequence of word1[i..n-1]
        vector<int> suf(n + 1, 0);
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];
            if (j >= 0 && word1[i] == word2[j]) {
                suf[i]++;
                j--;
            }
        }
        
        vector<int> ans;
        j = 0;
        bool mismatched = false;
        
        for (int i = 0; i < n && j < m; i++) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            } else if (!mismatched && suf[i + 1] >= m - j - 1) {
                ans.push_back(i);
                mismatched = true;
                j++;
            }
        }
        
        if (j != m) return {};
        return ans;
    }
};
