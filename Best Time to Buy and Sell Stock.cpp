class Solution {
public:
    int maxProfit(vector<int> &prices) {
        
        if( !prices.size() ) return 0;
        
        int mini = prices[0];
        int n = prices.size();
        int ret = 0;
        
        for( int i = 0; i < n; i++ ) {
            mini = min( mini , prices[i] );
            ret = max( ret , prices[i] - mini );
        }
        
        return ret;
    }
};
