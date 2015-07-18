class Solution {
public:
    int product( int A[], int L, int R ) {
        if( L > R ) return INT_MIN;
        int ret = 1;
        for( int i = L; i <= R; i++ ) {
            ret *= A[i];
        }
        return ret;
    }
    int myMaxProduct(int A[], int L, int R ) {
        
        if( R < L ) return INT_MIN;
        if( L == R ) return A[L];
        
        int minus = 0;
        int Leftmost = -1, Rightmost = -1;
        
        for( int i = L; i <= R; i++ ) if( A[i] < 0 ) {
            if( Leftmost == -1 ) Leftmost = i;
            Rightmost = i;
            minus++;
        }
        
        if( minus % 2 == 0 ) return product( A, L, R );
        
        return max( product( A , L , Rightmost - 1 ) , product( A , Leftmost + 1 , R ) ) ;
    }
    int maxProduct( int A[], int n ) {
        int i = 0, ret = INT_MIN;
        
        for( int k = 0; k < n; k++ ) ret = max( ret , A[k] );
        
        while( i < n && A[i] == 0 ) i++;
        
        while( i < n ) {
            int j = i;
            while( j < n && A[j] != 0 ) j++;
            ret = max( ret , myMaxProduct( A , i , j-1 ) );
            while( j < n && A[j] == 0 ) j++;
            i = j;
        }
        
        return ret;
    }
};
