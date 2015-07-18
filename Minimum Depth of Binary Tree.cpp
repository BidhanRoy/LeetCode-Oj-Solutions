/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        if( !root ) return 0;
        int ret = -1;
        if( root->left ) ret = minDepth( root->left ) + 1;
        if( root->right ) {
            if( ret == -1 ) ret = minDepth( root->right ) + 1;
            else ret = min( ret , minDepth( root->right ) + 1 );
        }
        if( ret == -1 ) ret = 1;
        return ret;
    }
};
