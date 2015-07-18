class Solution {
public:
    int largestRect( int *dp, int n ) {
        stack<int> st;
        int i = 0, ret = 0;
        while( i < n ) {
            if( st.empty() || dp[ st.top() ] < dp[i] ) st.push( i++ );
            else  {
                int top = st.top();
                st.pop();
                int Left = -1;
                if( st.size() ) Left = st.top();
                int Right = i;
                ret = max( ( Right - Left - 1 ) * dp[top] , ret ); 
            }
        }
        
        int Right = n;
        while( st.size() ) {
            int top = st.top(); st.pop();
            int Left = -1;
            if( st.size() ) Left = st.top();
            ret = max( ( Right - Left - 1 ) * dp[top] , ret );
        }
        
        return ret;
    }
    
    int maximalRectangle(vector<vector<char> > &matrix) {
        int r = matrix.size();
        if( !r ) return 0;
        int c = matrix[0].size();
        
        int dp[c], ret = 0;
        
        memset( dp, 0, sizeof dp );
        
        for( int i = 0; i < r; i ++ ) {
            for( int j = 0; j < c; j++ ) {
                if( matrix[i][j] == '0' ) dp[j] = 0;
                else dp[j]++;
            }
            ret = max( ret, largestRect(dp,c) );
        }
        
        return ret;
    }
};
