class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int ret = 0;
        for( int i = prices.size() - 1; i > 0; i-- ) ret += max( 0 , prices[i] - prices[i-1] );
        return ret;
    }
};
