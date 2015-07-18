class Solution {
public:
    int dp[202][102];
    int uniquePaths(int m, int n) {
        dp[0][0] = 1;
        for( int i = 1; i <= m+n; i++ )
            for( int j = 0; j <= i && j <= n; j++ )
                if( !j ) dp[i][j] = 1;
                else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        return dp[m+n-2][n-1];
    }
};
