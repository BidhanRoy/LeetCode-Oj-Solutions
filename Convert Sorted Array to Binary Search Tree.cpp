class Solution {
public:
    TreeNode *call( int i, int j, vector<int> &num ) {
        if(i>j) return NULL;
        int mid = (i+j)/2;
        TreeNode *ret = new TreeNode( num[mid] );
        ret->left = call(i,mid-1,num);
        ret->right = call(mid+1,j,num);
        return ret;
    }
    TreeNode *sortedArrayToBST(vector<int> &num) {
        return call( 0, int(num.size())-1 , num );
    }
};

