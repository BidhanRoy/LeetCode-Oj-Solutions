/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:

    unordered_map< UndirectedGraphNode * , UndirectedGraphNode * > Map;

    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        
        if( !node ) return NULL;
        
        if( Map.count( node ) ) return Map[ node ];
        
        UndirectedGraphNode *newNode = new UndirectedGraphNode( node->label );
        
        Map[ node ] = newNode;
        
        for( auto x : node->neighbors )
            newNode->neighbors.push_back( cloneGraph( x ) );
        
        return Map[ node ];
    }
};
