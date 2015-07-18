class Solution {
public:
    
    int rPivot( int A[], int n ) {
        int lo = 0, hi = n-1, ret = -1;
        while( lo <= hi ) {
            int mid = ( lo + hi ) / 2;
            if( A[mid] < A[0] ) {
                hi = mid - 1;
                ret = ( ret == -1 ? mid : min( ret , mid ) );
            }
            else lo = mid + 1;
        }
        if( ret == -1 ) ret = 0;
        return ret;
    }
    
    int binarySearch( int A[], int L, int R, int v ) {
        while( L <= R ) {
            int mid = ( L + R ) / 2;
            if( v < A[mid] ) R = mid - 1;
            else if( v > A[mid] ) L = mid + 1;
            else return mid;
        }
        return -1;
    }
    
    int search(int A[], int n, int target) {
        int piv = rPivot( A, n );
        return max( binarySearch( A, 0, piv-1, target ) ,
                    binarySearch( A, piv, n-1, target ) );
    }
};
