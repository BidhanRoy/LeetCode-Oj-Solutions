class Solution {
public:
    bool isPalindrome(long long x) {
        if( !x ) return true;
        if( x < 0 ) return false;
        long long left = 1, right = x;
        while( left <= x / 10 ) left *= 10;

        while( right ) {
            if( ( x / left ) % 10 != right % 10 ) return false;
            right /= 10;
            left /= 10;
        }

        return true;
    }
};
