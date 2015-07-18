class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        int n = s.size();
        
        vector< int > dp(n+1,0);
        
        dp[n] = 1;
        
        for( int i = n-1; i >= 0; i-- ) {
            string temp;
            for( int j = i; j < n; j++ ) {
                temp += s[j];
                if( dict.count( temp ) && dp[j+1] ) {
                    dp[i] = 1;
                    break;
                }
            }
        }
        
        return dp[0];
    }
};
