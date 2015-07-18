class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int i = 0, ret = 0, n = s.size();
        
        while( i < n ) {
            if( s[i] == '(' ) st.push( i );
            else {
                if( !st.empty() && s[ st.top() ] == '(' ) {
                    st.pop();
                    int left = -1;
                    if( st.size() ) left = st.top();
                    ret = max( ret , i - left );
                }
                else st.push(i);
            }
            i++;
        }
        
        return ret;
    }
};
