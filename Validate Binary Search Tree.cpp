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
    bool isValidBST(TreeNode* root, int _min=INT_MIN, int _max=INT_MAX) {
        if(!root)
            return true;
        if(root->val < _min || _max < root->val)
            return false;
        // for max/min int values
        if(root->val == _min && root->left)
            return false;
        if(root->val == _max && root->right)
            return false;
        return isValidBST(root->left, _min, root->val-1) &&
                isValidBST(root->right, root->val+1, _max);
    }
};
