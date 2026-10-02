class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while (!q.empty()) {
            depth++;
            int n = q.size();

            // Process every node at the current level
            while (n > 0) {
                TreeNode* node = q.front(); // Move inside the loop
                q.pop();                   // Move inside the loop

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }

                n--;
            }
        }

        return depth;
    }
};