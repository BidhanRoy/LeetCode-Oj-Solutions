/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int R, int L=1) {
        vector<TreeNode*> ret;
        
        for(int i=L; i<=R; i++) {
            
            auto leftList = generateTrees(i-1, L);
            auto rightList = generateTrees(R, i+1);
            
            for(auto &L: leftList)
                for(auto &R: rightList) {
                    TreeNode *current = new TreeNode(i);
                    current->left = L;
                    current->right = R;
                    ret.push_back(current);
                }
        }
        
        if(!ret.size()) ret.push_back(NULL);
        return ret;
    }
};
