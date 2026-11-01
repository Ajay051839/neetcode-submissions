class Solution {
   public:
    bool IsGreaterOrEqual(unordered_map<char, int> mp1, unordered_map<char, int> mp2) {
        for (auto i : mp1) {
            if (mp2[i.first] >= i.second)
                continue;
            else {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";
        int left = 0;
        vector<int> ans(2);
        int mnLength = INT_MAX;

        unordered_map<char, int> mp1;
        for (int i = 0; i < m; i++) {
            mp1[t[i]]++;
        }
        int right;
        unordered_map<char, int> mp2;

        for (right = 0; right < n; right++) {
            mp2[s[right]]++;
            if (IsGreaterOrEqual(mp1, mp2)) {
                if ((right - left + 1) < mnLength) {
                    ans[0] = left;
                    ans[1] = right;
                    mnLength = (right - left + 1);
                }
                while (IsGreaterOrEqual(mp1, mp2) && left < right) {
                    mp2[s[left]]--;
                    left++;
                    if (IsGreaterOrEqual(mp1, mp2) && (right - left + 1) < mnLength) {
                        ans[0] = left;
                        ans[1] = right;
                        mnLength = right - left + 1;
                    }
                }
            }
        }
        string g = s.substr(ans[0], mnLength);
        return g;
    }
};
