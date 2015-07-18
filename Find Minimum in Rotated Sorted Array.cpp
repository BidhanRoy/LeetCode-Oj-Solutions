class Solution {
public:
    int findMin(vector<int> &num) {
        int lo = 0, hi = num.size() - 1, ret = -1;
        while( lo <= hi ) {
            int mid = ( lo + hi ) / 2;
            if( num[mid] < num[0] ) {
                hi = mid - 1;
                if( ret == -1 || ret > mid ) ret = mid;
            }
            else lo = mid + 1;
        }
        if( ret == -1 ) ret = 0;
        return num[ ret ];
    }
};
