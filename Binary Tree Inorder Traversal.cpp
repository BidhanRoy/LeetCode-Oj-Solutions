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
    void dfs( TreeNode *v, vector<int> &vec ) {
        if( !v ) return ;
        dfs( v->left, vec );
        vec.push_back( v->val );
        dfs( v->right, vec );
    }
    
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> ret;
        dfs( root, ret );
        return ret;
    }
};
