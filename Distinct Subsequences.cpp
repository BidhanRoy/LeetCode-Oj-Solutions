class Solution {
public:
    int numDistinct(string S, string T) {
        int n = S.size(), m = T.size();
        int dp[n+1][m+1];
        
        memset( dp, 0, sizeof dp );
        dp[0][0] = 1;
        
        for( int i = 1; i <= n; i++ ) {
            for( int j = 0; j <= m; j++ ) {
                if( !j ) {
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i-1][j];
                if( S[i-1] == T[j-1] ) dp[i][j] += dp[i-1][j-1];
            }
        }
        
        return dp[n][m];
    }
};
