class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int n = strlen( s );
        int m = strlen( p );
        int i = 0, j = 0, star = -1;
        int store = -1;

        while( i<n ) {
            if( j<m && ( s[i] == p[j] || p[j] == '?' ) ) {
                i++, j++;
                continue;
            }

            if( j<m && p[j] == '*' ) {
                star = j++;
                store = i;
                continue;
            }

            if( store > -1 ) {
                j = star;
                i = store + 1;
                continue;
            }

            break;
        }

        while( j<m && p[j] == '*' ) j++;

        return (i==n && j==m);
    }
};
