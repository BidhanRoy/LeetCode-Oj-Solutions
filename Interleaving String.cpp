class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int L = s3.size();

        if( n+m != L ) return false;
        if( n+m == 0 ) return true;
        if( !n ) return (s2==s3);
        if( !m ) return (s1==s3);

        int dp[L+1][n+1];

        memset(dp,0,sizeof(dp));

        for( int i = 0; i <= L; i++ ){
            for( int j = 0; j <= min( i , n ); j++ ) {
                if( !i && !j ) { dp[i][j] = 1; continue; }
                int k = i - j;
                if( k > m ) continue;
                if( k && s3[i-1] == s2[k-1] && dp[i-1][j] ) dp[i][j] = 1;
                else if( j && s3[i-1] == s1[j-1] && dp[i-1][j-1] ) dp[i][j] = 1;
            }
        }

        return dp[L][n];
    }
};
