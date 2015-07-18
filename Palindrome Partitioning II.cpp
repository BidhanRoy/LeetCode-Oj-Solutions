class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        vector<int> Dp( n+1, 0 );
        vector<unsigned long long> F(n+1,0), R(n+1,0), P(n+1,0);

        P[0] = 1;
        for( int i = 0; i < n; i++ ) {
            P[i+1] = P[i] * 31ll;
            if(i) F[i] = F[i-1];
            F[i] += P[i] * s[i];
        }

        for( int i = n-1; i >= 0; i-- ) {
            if( i < n-1 ) R[i] = R[i+1];
            R[i] += P[ n - i - 1 ] * s[i];
        }

        for( int i = n-1; i >= 0; i-- ) {
            Dp[i] = Dp[i+1] + 1;
            for( int j = i; j <n ; j++ ) {
                unsigned long long ff = F[j]; if(i) ff -= F[i-1];
                unsigned long long rr = R[i]; if(j+1<n) rr -= R[j+1];


                if( n - j - 1 > i ) ff *= P[ n - j - 1 - i ];
                else rr *= P[ i - n + j + 1 ];

                if( ff == rr ) {
                    Dp[i] = min( Dp[i] , Dp[j+1] + 1 );
                }
            }
        }

        return Dp[0] - 1;
    }
};

