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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        int cnt = bool( p == NULL ) + bool( q == NULL );
        if( cnt == 1 ) return false;
        if( cnt == 2 ) return true;
        if( p->val != q->val ) return false;
        
        if( !isSameTree( p->left , q->left ) ||
            !isSameTree( p->right , q->right ) ) return false;
        
        return true;
    }
};
