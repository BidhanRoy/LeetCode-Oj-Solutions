class Solution {
public:
    int maximumGap(vector<int> &num) {
        
        int n = num.size();
        
        if( n < 2 ) return 0;
        if( n == 2 ) return abs( num[0] - num[1] );
        
        int Min = *min_element( num.begin() , num.end() );
        int Max = *max_element( num.begin() , num.end() );
        
        double d = double( Max - Min ) / ( n - 1 );
        
        vector< int > maxV( n - 1 , -1 );
        vector< int > minV( n - 1 , -1 );
        
        for( int x : num ) {
            int hop = ( x == Max ? n-2 : double( x - Min ) / d );
            maxV[hop] = max( maxV[hop] , x );
            if( minV[hop] == -1 || minV[hop] > x ) minV[hop] = x;
        }
        
        n--;
        int i = 0, ret = 0;
        while( i < n && minV[i] == -1 ) i++;
        while( i < n ) {
            int j = i+1;
            while( j < n && minV[j] == -1 ) j++;
            if( j == n ) break;
            ret = max( ret , minV[j] - maxV[i] );
            i = j;
        }
        
        return ret;
    }
};
