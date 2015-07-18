class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set< char > ase;
        
        int n = s.size(), i = 0, j = 0, ret = 0;;
        
        while( true ) {
            if( j < n && !ase.count( s[j] ) ) {
                ase.insert( s[j] );
                j++;
                ret = max( ret, j - i );
            }
            else if( i < j ) {
                ase.erase( s[i] );
                i++;
            }
            else if( i < n ) i++, j++;
            else break;
        }
        
        return ret;
        
    }
};
