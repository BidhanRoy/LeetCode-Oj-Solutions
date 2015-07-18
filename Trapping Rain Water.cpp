class Solution {
public:
    int trap(int A[], int n) {
        int ret = 0;
        if( n < 3 ) return ret;
        stack<int> st;
        for( int i = 0; i < n; i++ ){
            if( st.empty() || A[ st.top() ] >= A[i] ) st.push( i );
            else{
                while( st.size() && A[st.top()] < A[i] ){
                    int top = st.top();
                    st.pop();
                    int Left = -1;
                    if( st.size() ) Left = st.top();
                    int Right = i;
                    if( Left != -1 ) ret += max( min( A[Left] , A[Right] ) - A[top] , 0 ) * ( Right - Left - 1 );
                }
                st.push(i);
            }
        }
        return ret;
    }
};
