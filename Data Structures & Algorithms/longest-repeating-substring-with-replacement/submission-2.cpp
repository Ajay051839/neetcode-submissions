class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> count(26, 0);
        int maxFreq = 0;
        int start = 0;
        int maxLen = 0;

        for (int end = 0; end < s.size(); end++) {
            count[s[end] - 'A']++;
            maxFreq = max(maxFreq, count[s[end] - 'A']);

            // Window is valid if: (window size - maxFreq) <= k
            while ((end - start + 1) - maxFreq > k) {
                count[s[start] - 'A']--;
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};