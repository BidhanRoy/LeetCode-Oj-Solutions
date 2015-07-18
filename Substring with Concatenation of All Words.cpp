class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        vector<int> ret;
        int n = S.size();
        int len = L.size();

        if( !len ) return ret;

        unordered_map< string , int > occ;

        for( string &x : L ) occ[x]++;

        int m = L[0].size();
        for( int start = 0; start < min( m, n ); start++ ) {

            auto myOcc = occ;
            int i = start, j = start, cnt = len;

            while( i < n || j < n ) {
                if( j < n && myOcc.count( S.substr( j, m ) ) > 0 && myOcc[ S.substr( j, m ) ] > 0 ) {
                    myOcc[ S.substr( j, m ) ]--;
                    cnt--;
                    j+=m;
                    if( !cnt ) ret.push_back( j - len * m );
                }
                else if( i < j ) {
                    myOcc[ S.substr( i, m ) ]++;
                    cnt++;
                    i+=m;
                }
                else if( i < n ) {
                    i += m;
                    j += m;
                }
                else break;
            }
        }

        return ret;
    }
};

