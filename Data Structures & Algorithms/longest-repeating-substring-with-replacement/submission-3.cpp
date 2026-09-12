class Solution {
   public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26);
        int mxFreq = 0;
        int start = 0;
        int ans = 0;
        for (int end = 0; end < n; end++) {
            freq[s[end] - 'A']++;
            mxFreq = max(mxFreq, freq[s[end] - 'A']);
            if ((end + 1 - start - mxFreq) > k) {
                freq[s[start] - 'A']--;
                start++;
            }
            ans = max(ans, end - start + 1);
        }
        return ans;
    }
};
