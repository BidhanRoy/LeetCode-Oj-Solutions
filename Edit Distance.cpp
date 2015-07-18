class Solution {
public:
    int minDistance(string word1, string word2) {
        int N = word1.size();
        int M = word2.size();
        int dp[N+1][M+1];
        
        for( int i = 0; i <= N; i++ ) {
            for( int j = 0; j <= M; j++ ) {
                if( !i && !j ) dp[i][j] = 0;
                else if( !i ) dp[i][j] = dp[i][j-1] + 1;
                else if( !j ) dp[i][j] = dp[i-1][j] + 1;
                else {
                    dp[i][j] = INT_MAX;
                    if( word1[i-1] == word2[j-1] ) dp[i][j] = dp[i-1][j-1]; /// no need to change the character
                    else dp[i][j] = dp[i-1][j-1] + 1; /// changing the character
                    
                    dp[i][j] = min( dp[i][j] , min( dp[i-1][j] + 1, dp[i][j-1] + 1 ) );
                }
            }
        }
        
        return dp[N][M];
    }
};
