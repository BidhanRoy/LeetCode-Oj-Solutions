class Solution {
public:
    pair< int, int > call( TreeNode *now ) {
        /// first = as a root of Tree
        /// second = as a root of Chain
        pair< int, int > ret, L, R;

        ret = { now->val, now->val };

        if( now->left ) {
            L = call( now->left );
            if( ret.first + L.second > ret.first ) ret.first += L.second;
            ret.second = max( ret.second, now->val + L.second ); 
        }

        if( now->right ) {
            R = call( now->right );
            if( ret.first + R.second > ret.first ) ret.first += R.second;
            ret.second = max( ret.second, now->val + R.second );
        }
        
        ret.first = max( ret.first , ret.second );

        if( now->left ) ret.first = max( ret.first, L.first );
        if( now->right ) ret.first = max( ret.first, R.first );

        return ret;
    }

    int maxPathSum(TreeNode *root) {
        if( !root ) return 0;
        return call( root ).first;
    }
};
