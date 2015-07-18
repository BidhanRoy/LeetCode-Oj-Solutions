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
    pair< int , int > call( TreeNode *root ) {
        pair< int , int > ret = { 0, 0 };
        
        if( root->left ) {
            auto now = call( root->left );
            ret.first += now.first;
            ret.second += now.second;
        }
        
        if( root->right ) {
            auto now = call( root->right );
            ret.first += now.first;
            ret.second += now.second;
        }
        
        if( ret.second ) ret.second *= 10;
        else ret.second = 1;
        
        ret.first += root->val * ret.second;
        
        return ret;
        
    }
    
    int sumNumbers(TreeNode *root) {
        if( !root ) return 0;
        return call( root ).first;
    }
};
