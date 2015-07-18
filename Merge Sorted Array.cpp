class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int i = m - 1, j = n - 1;
        int index = n + m - 1;
        while( i > -1 && j > -1 ) {
            if( A[i] > B[j] ) A[ index-- ] = A[i--];
            else A[ index-- ] = B[j--];
        }
        while( i > -1 ) A[ index-- ] = A[i--];
        while( j > -1 ) A[ index-- ] = B[j--];
    }
};
