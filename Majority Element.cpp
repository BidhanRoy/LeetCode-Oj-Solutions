class Solution {
public:
    int partition( vector<int> &num, int L, int R ) {
        int i = L, storeIndex = L;
        while( i<=R ) {
            if( num[i] < num[R] ) swap( num[storeIndex++] , num[i] );
            i++;
        }
        swap(num[storeIndex],num[R]);
        return storeIndex;
    }
    int findKth( vector<int> &num, int L, int R, int k ) {
        if( L > R ) throw;
        int index = partition( num, L, R );
        if( index+1-L == k ) return num[L+k-1];
        else if( index+1-L < k ) return findKth( num, index+1, R, k - index - 1 + L );
        return findKth( num, L, index-1, k );
    }
    int majorityElement(vector<int> &num) {
        return findKth( num, 0, num.size()-1, (num.size()+1)/2 );
    }
};
