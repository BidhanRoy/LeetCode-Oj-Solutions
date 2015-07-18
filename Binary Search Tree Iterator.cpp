/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    stack< TreeNode * > st;
    TreeNode *current;
    /// 0 = processing left
    /// 1 = processing right
    /// 2 = processing finished
    
    TreeNode* Traverse( TreeNode *root ) {
        st.push( root );
        if( root->left ) return Traverse( root->left );
        return root;
    }
    
    BSTIterator(TreeNode *root) {
        if(root) current = Traverse(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return st.size();
    }

    /** @return the next smallest number */
    int next() {
        auto ret = st.top();
        st.pop();
        if( ret->right ) Traverse( ret->right );
        return ret->val;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
