class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int N = strlen( s );
        int M = strlen( p );

        int dp[N+1][M+1];
        memset( dp, 0, sizeof(dp) );
        
        dp[0][0] = 1;
        for( int i = 0; i <= N; i++ ){
            for( int j = 0; j <= M; j++ ){
                if( !i && !j ) { dp[i][j] = 1; continue; }            
                if( j && p[j-1] == '*' ) { 
                    dp[i][j] = dp[i][j-1];
                    if( j > 1 ) dp[i][j] |= dp[i][j-2];
                    continue; 
                }
                if( i && j && p[j-1] == '.' || s[i-1] == p[j-1] ) {
                    if( dp[i-1][j-1] ) dp[i][j] = 1;
                    else if( j<M && p[j] == '*' && dp[i-1][j] ) dp[i][j] = 1;
                }
            }
        }
        
        return dp[N][M];
    }
};
