/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        if( !head ) return NULL;
        
        int len = 0;
        ListNode *temp = head;
        while( temp ) temp = temp->next, len++; /// computing length
        
        len /= 2;
        temp = head;
        ListNode *prev = NULL;
        while( len-- ) {
            prev = temp;
            temp = temp->next; /// temp is now at middle
        }
        
        TreeNode *now = new TreeNode( temp->val );
        if( prev ) prev->next = NULL;
        
        now->left = ( head == temp? NULL : sortedListToBST( head ) );
        now->right = sortedListToBST( temp->next );
        
        return now;
    }
};
