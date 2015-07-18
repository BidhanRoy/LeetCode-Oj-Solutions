class Solution {
public:
    int sqrt(int x) {
        double lo = 0, hi = INT_MAX;
        int stp = 200;
        while( stp-- ) {
            double mid = ( lo + hi ) / 2.0;
            if( mid * mid > x ) hi = mid;
            else if( mid * mid < x ) lo = mid;
        }
        return ( lo + hi ) / 2.0;
    }
};

