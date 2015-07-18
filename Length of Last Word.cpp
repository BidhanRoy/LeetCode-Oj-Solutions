class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int length = 0, ret = 0;
        for( int i = 0; s[i]; i++ ) {
            if( s[i] == ' ' ) {
                if( length > 0 ) ret = length;
                length = 0;
            }
            else length++;
        }
        if( length > 0 ) ret = length;
        return ret;
    }
};
