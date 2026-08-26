class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> trustScore(n + 1, 0);

        for (const auto& t : trust) {
            trustScore[t[0]]--; // trusts someone (out-degree)
            trustScore[t[1]]++; // trusted by someone (in-degree)
        }

        for (int i = 1; i <= n; i++) {
            if (trustScore[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};