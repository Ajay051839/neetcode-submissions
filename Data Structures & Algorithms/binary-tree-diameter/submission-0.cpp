/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int height(TreeNode* root){
        if(root==nullptr)return 0;
        int leftH=height(root->left);
        int rightH=height(root->right);
        return 1+max(leftH,rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr)return 0;
        int leftH=height(root->left);
        int rightH=height(root->right);
        int diameter=leftH+rightH;
        int mx=max(diameterOfBinaryTree(root->left),diameterOfBinaryTree(root->right));
        return max(mx,diameter);
    }
};
