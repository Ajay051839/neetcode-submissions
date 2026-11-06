class Solution {
public:
    void Helper(int indx, int n, int k, vector<vector<int>>& ans, vector<int>& temp) {
        // Base Case 1: Found a valid combination of size k
        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        // Base Case 2: Out of bounds
        if (indx > n) {
            return;
        }
        
        // Option 1: Take current element
        temp.push_back(indx);
        Helper(indx + 1, n, k, ans, temp);
        temp.pop_back(); // Backtrack
        
        // Option 2: Skip current element
        Helper(indx + 1, n, k, ans, temp);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        Helper(1, n, k, ans, temp);
        return ans;
    }
};