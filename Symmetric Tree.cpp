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
    bool equal( TreeNode *a, TreeNode *b ) {
        if( a == NULL && b == NULL ) return true;
        if( a == NULL || b == NULL ) return false;
        if( a->val != b->val ) return false;
        if( !equal( a->left , b->right ) ||
            !equal( a->right , b->left ) ) return false;
        return true;
        
    }
    bool isSymmetric(TreeNode *root) {
        if( root == NULL ) return true;
        return equal( root->left , root->right );
    }
};
