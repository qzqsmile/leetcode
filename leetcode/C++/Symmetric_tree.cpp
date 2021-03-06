/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return compareTree(root->left, root->right);
    }
    
    bool compareTree(TreeNode *node1, TreeNode *node2)
    {
        if((node1 && node2) && (node1->val == node2->val))
            return compareTree(node1->left, node2->right) && compareTree(node1->right, node2->left);
        if((node1 == node2) && (node1 == NULL))
            return true;
        return false;
    }
};