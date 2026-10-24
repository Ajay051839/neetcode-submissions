
class Solution {
public:
    bool isEqual(TreeNode* root1, TreeNode* root2) {
        // Both trees are empty
        if (root1 == nullptr && root2 == nullptr)
            return true;

        // Only one tree is empty
        if (root1 == nullptr || root2 == nullptr)
            return false;

        // Values differ
        if (root1->val != root2->val)
            return false;

        // Compare corresponding left and right subtrees
        return isEqual(root1->left, root2->left) &&
               isEqual(root1->right, root2->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // An empty subtree is always a subtree
        if (subRoot == nullptr)
            return true;

        // A non-empty subtree cannot exist in an empty tree
        if (root == nullptr)
            return false;

        // Check whether the trees match at this node
        if (isEqual(root, subRoot))
            return true;

        // Otherwise, search the left and right subtrees
        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
