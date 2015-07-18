class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> st;
        int i = 0, n = height.size(), ret = 0;
        
        while( i < n ) {
            if( st.empty() || height[ st.top() ] < height[i] ) st.push( i++ );
            else {
                if( height[ st.top() ] >= height[i] ) {
                    int idx = st.top(), Left, Right;
                    st.pop();
                    Left = -1;
                    if( st.size() ) Left = st.top();
                    Right = i;
                    ret = max( ret , ( Right - Left - 1 ) * height[idx] );
                } 
            }
        }
        
        while( st.size() ) {
            int idx = st.top(), Left, Right;
            st.pop();
            Left = -1;
            if( st.size() ) Left = st.top();
            Right = n;
            ret = max( ret , ( Right - Left - 1 ) * height[idx] );
        }
        
        return ret;
    }
};
