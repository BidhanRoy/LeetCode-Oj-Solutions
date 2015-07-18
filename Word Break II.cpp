class Solution {
public:
    vector<string> call( int pos, int n, string &S, int *dp, unordered_set<string> &dict ) {
        vector<string> ret;
        string now = "";
        for( int j = pos; j < n; j++ ) {
            now += S[j];
            if( dict.count( now ) && dp[j+1] ) {
                if( j+1 == n ) ret.push_back( now );
                else {
                    vector<string> temp = call( j+1, n, S, dp, dict );
                    for( string &x : temp ) ret.push_back( now + " " + x );
                }
            }
        }
        return ret;
    }
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size(), dp[n+1];

        dp[n] = 1;

        for( int i = n-1; i >= 0; i-- ) {
            string now = "";
            dp[i] = 0;
            for( int j = i; j < n; j++ ) {
                now += s[j];
                if( dict.count( now ) && dp[j+1] ) { dp[i] = 1; break; }
            }
        }

        vector<string> ret;

        if( !dp[0] ) return ret;

        return call( 0, n, s, dp, dict );
    }
};
