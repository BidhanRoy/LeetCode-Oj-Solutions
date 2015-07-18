class Solution {
public:
    string minWindow(string S, string T) {
        unordered_map<char,int> ase;
        int i = 0, j = 0, n = S.size();
        for( char x : T ) ase[x]++;
        int cnt = ase.size();
        
        unordered_map<char,int> got;
        
        int L, window = INT_MAX;
        
        while( true ) {
            if( j < n && cnt > 0 ) {
                if( ase.count( S[j] ) ) {
                    got[ S[j] ]++;
                    if( got[ S[j] ] == ase[ S[j] ] ) cnt--;
                }
                j++;
            }
            else if( !cnt ) {
                if( window > j - i ) window = j - i, L = i;
                if( ase.count( S[i] ) ) {
                    got[ S[i] ]--;
                    if( got[ S[i] ] < ase[ S[i] ] ) cnt++;
                }
                i++;
            }
            else break;
        }
        
        if( window == INT_MAX ) return "";
        return S.substr( L, window );
        
    }
};
