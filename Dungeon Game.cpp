class Solution {
public:
    int calculateMinimumHP(vector<vector<int> > &dungeon) {
        int r = dungeon.size();
        if( !r ) return 0;
        int c = dungeon[0].size();
        if( !c ) return 0;

        vector< vector<int> > dp( r+1, vector<int>(c+1,INT_MAX) );

        dp[r][c-1] = dp[r-1][c] = 1;

        for( int i=r-1; i>=0; i-- ) {
            for( int j=c-1; j>=0; j-- ) {
                dp[i][j] = min( dp[i+1][j] , dp[i][j+1] );
                if( dungeon[i][j] >= dp[i][j] ) dp[i][j] = 1;
                else dp[i][j] -= dungeon[i][j];
            }
        }

        return dp[0][0];
    }
};
