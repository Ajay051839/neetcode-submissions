class Solution {
public:
    // Pass by const reference to avoid expensive copying
    bool IsGreaterOrEqual(const unordered_map<char, int>& mp1, const unordered_map<char, int>& mp2) {
        for (auto i : mp1) {
            // mp2.at() or find() is safer, but operator[] works if keys exist/insert 0.
            auto it = mp2.find(i.first);
            if (it == mp2.end() || it->second < i.second) {
                return false;
            }
        }
        return true; // Moved outside the loop!
    }

    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";
        
        int left = 0;
        int ans_left = 0; // Track start of best window
        int mnLength = INT_MAX;

        unordered_map<char, int> mp1;
        for (int i = 0; i < m; i++) {
            mp1[t[i]]++;
        }
        
        unordered_map<char, int> mp2;
        int matched = 0;

        for (int right = 0; right < n; right++) {
            mp2[s[right]]++;

            // While current window contains all characters of t
            while (IsGreaterOrEqual(mp1, mp2)) {
                // Update minimum length configuration
                if ((right - left + 1) < mnLength) {
                    mnLength = (right - left + 1);
                    ans_left = left;
                }
                
                // Try to shrink from the left
                mp2[s[left]]--;
                left++;
            }
        }

        return (mnLength == INT_MAX) ? "" : s.substr(ans_left, mnLength);
    }
};