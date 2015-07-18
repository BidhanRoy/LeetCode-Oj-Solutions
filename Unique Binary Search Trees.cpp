class Solution {
public:
    int numTrees(int n) {
        vector< vector<int> > dp( n , vector<int> ( n , 0 ) );
        for( int L = 1; L <= n; L++ ) {
            for( int i = 0 , j = i + L - 1; j < n; i++, j++ ) {
                if( L == 1 ) {
                    dp[i][j] = 1;
                    continue;
                }
                for( int k = i; k <= j; k++ ) {
                    int L = 1;
                    int R = 1;
                    if( i <= k-1 ) L = dp[i][k-1];
                    if( k+1 <= j ) R = dp[k+1][j];
                    dp[i][j] += L * R;
                }
            }
        }
        return dp[0][n-1];
    }
};
