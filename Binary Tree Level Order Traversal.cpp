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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector< vector<int> > ret;
        if( !root ) return ret;
        
        queue< TreeNode * > q, temp;
        q.push( root );
        
        while(!q.empty()) {
            vector<int> now;
            while( !q.empty() ) {
                TreeNode *top = q.front();
                q.pop();
                now.push_back(top->val);
                if( top->left ) temp.push( top->left );
                if( top->right ) temp.push( top->right );
            }
            ret.push_back( now );
            while( !temp.empty() ) {
                q.push( temp.front() );
                temp.pop();
            }
        }
        
        return ret;
        
    }
};
