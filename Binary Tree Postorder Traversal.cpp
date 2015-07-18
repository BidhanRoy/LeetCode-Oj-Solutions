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
    void call( TreeNode *root, vector<int> &ans ) {
        if( root->left ) call( root->left, ans );
        if( root->right ) call( root->right, ans );
        ans.push_back( root->val );
    }
    vector<int> postorderTraversal(TreeNode *root) {
        vector< int > ret;
        if( !root ) return ret;
        call( root, ret );
        return ret;
    }
};
