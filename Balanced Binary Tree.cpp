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
    bool isBalanced(TreeNode* root, int *height=NULL) {
        if(!height) height = new int(0);
        if(!root) return true;
            
        int leftHeight(0), rightHeight(0);
        
        if(isBalanced(root->left, &leftHeight) &&
            isBalanced(root->right, &rightHeight) &&
            abs(leftHeight - rightHeight) < 2) {
            *height = max(leftHeight, rightHeight)+1;
            return true;
        }
        
        return false;
    }
};
