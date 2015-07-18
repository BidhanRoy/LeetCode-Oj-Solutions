class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = 0;
        for( int bit = 0; bit < 32; bit++ ) {
            int cnt = 0;
            for( int i = 0; i < n; i++ ) {
                cnt += bool( A[i] & (1<<bit) );
            }
            ret += bool(cnt%3)<<bit;
        }
        return ret;
    }
};
