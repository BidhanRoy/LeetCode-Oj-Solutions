class Solution {
public:
    string call( int n, int length ) {
        if( !length ) return "";
        return call( n / 26, length - 1 ) + string( 1 , n % 26 + 'A' );
    }
    string convertToTitle(int n) {
        long long mul = 26;
        int length = 1;
        while( mul < n ) {
            n -= mul;
            length++;
            mul *= 26;
        }
        return call( n - 1, length );
    }
};
