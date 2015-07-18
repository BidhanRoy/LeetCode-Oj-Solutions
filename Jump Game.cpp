class Solution {
public:
    bool canJump(int A[], int n) {
        int nowAt = 0, canGo = 0;
        while( nowAt < n ) {
            canGo = max( canGo , nowAt + A[nowAt] );
            if( nowAt == canGo ) break;
            nowAt++;
        }
        return nowAt >= n-1;
    }
};
