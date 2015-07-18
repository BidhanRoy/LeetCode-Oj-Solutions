class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        unordered_map< int , int > ase;
        for( int x : num ) ase[ x ] = -1;
        int ret = 0;
        for( int x : num ) {
            stack<int> st;
            while( ase.count(x) && ase[ x ] == -1 ) {
                st.push(x);
                x--;
            }
            int cnt = !ase.count(x)? 0 : ase[x];
            while( !st.empty() ){
                int top = st.top(); st.pop();
                cnt++;
                ase[top] = cnt;
            }
            ret = max( ret, cnt );
        }
        return ret;
    }
};
