class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int i = 0,  ret = 0, storeIndex = 0;
        while( i < n ) {
            int j = i;
            while( j < n && A[j] == A[i] ) j++;
            int len = min( j - i , 2 );
            while( len-- ) A[storeIndex++] = A[j-1];
            i = j;
        }
        return storeIndex;
    }
};
