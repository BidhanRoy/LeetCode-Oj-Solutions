class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size(), ret = 0;;
        
        vector< int > minF( n, INT_MAX ), pF(n, 0 );
        vector< int > maxR( n, INT_MIN ), pR(n, 0 );
        
        for( int i = 0; i < n; i++ ) {
            if( i ) minF[i] = minF[i-1], pF[i] = pF[i-1];
            minF[i] = min( minF[i] , prices[i] ); /// holds the min element untill i
            pF[i] = max( pF[i], prices[i] - minF[i] ); /// max profit can be made from 0 to i
        }
        
        for( int i = n-1; i >= 0; i-- ) {
            if( i < n-1 ) maxR[i] = maxR[i+1], pR[i] = pR[i+1];
            maxR[i] = max( maxR[i], prices[i] ); /// holds the max element untill i
            pR[i] = max( pR[i] , maxR[i] - prices[i] ); /// max profit can be made from n-1 to i
            
            ret = max( ret, pF[i]+pR[i] );
        }
        
        return ret;
    }
};
