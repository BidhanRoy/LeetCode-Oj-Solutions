/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:

    unordered_map< RandomListNode* , RandomListNode* > Map;
    
    RandomListNode *copyRandomList(RandomListNode *head) {
        if( !head ) return NULL;
        
        if( Map.count( head ) ) return Map[ head ];
        
        RandomListNode *now = new RandomListNode( head->label );
        
        Map[ head ] = now;
        
        now->next = copyRandomList( head->next );
        now->random = copyRandomList( head->random );
        
        return now;
    }
};
