class Solution {
public:
    
    int partition( int A[], int n ) {
        int storeIndex = n-1, i = n-1;
        while( i >= 0 ) {
            if( A[i] < 1 ) swap( A[storeIndex--] , A[i] );
            i--;
        }
        return storeIndex + 1;
    }
    
    int firstMissingPositive(int A[], int n) {
        n = partition( A, n );
        for( int i = 0; i < n; i++ ) {
            int index = A[i];
            while( index <= n && A[index-1] != index ) {
                int temp = A[index-1];
                A[index-1] = index;
                index = temp;
            }
        }
        for( int i = 0; i < n; i++ ) if( A[i] != i+1 ) return i+1;
        return n+1;
    }
};
