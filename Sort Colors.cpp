class Solution {
public:
    int partition( int A[], int L, int R, int v ) {
        int i = L, storeIndex = L;
        while( i <= R ) {
            if( A[i] < v ) swap( A[storeIndex++] , A[i] );
            i++;
        }
        return storeIndex;
    }
    void sortColors(int A[], int n) {
        int index = partition( A, 0, n-1, 1 );
        partition( A, index, n-1, 2 );
    }
};
