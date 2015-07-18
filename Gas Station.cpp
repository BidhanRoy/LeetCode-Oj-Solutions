class Solution {
public:
    int next( int idx , int n ) {
        idx++;
        if( idx >= n ) idx -= n;
        return idx;
    }
    int previous( int idx , int n ) {
        idx--;
        if( idx < 0 ) idx += n;
        return idx;
    }
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        int i = 0, j = 0, n = (int) gas.size(), sum = 0;

        while( i < n ) {
            if( gas[i] - cost[i] >= 0 ) {
                sum = gas[i] - cost[i];
                j = next( i , n );
                break;
            }
            i++;
        }

        if( i == n ) return -1;

        while( true ) {
            bool ent = false;
            while( j != i && sum + gas[ j ] - cost[ j ] >= 0 ) {
                sum += gas[ j ] - cost[ j ];
                j = next( j , n );
                ent = true;
            }
            int prev = previous( i , n );
            while( prev != previous( j , n ) && sum + gas[ prev ] - cost[ prev ] >= 0 ) {
                sum += gas[ prev ] - cost[ prev ];
                i = prev;
                prev = previous( i , n );
                ent = true;
            }
            if( !ent ) break;
        }
        if( i != j ) return -1;
        while( gas[i] - cost[i] < 0 ) i = next( i , n );
        return i;

    }
};
