class Solution {
public:
    double pow2(double x, int n) {
        double ret = 1;
        while( n > 0 ) {
            if( n & 1 ) ret *= x;
            x = x * x;
            n >>= 1;
        }
        return ret;
    }
    double pow(double x, int n) {
        if( n < 0 ) return pow2( 1.0/x , -n );
        return pow2( x, n );
    }
};
