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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode * root = NULL;
        root = build(nums, 0, nums.size()-1);
        return root;
    }
    
    TreeNode *build(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return NULL;
        int mid = (start + end) / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = build(nums, start, mid-1);
        root->right = build(nums, mid+1, end);
        
        return root;
    }
};