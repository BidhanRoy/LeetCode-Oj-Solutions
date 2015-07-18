class Solution {
public:
    void call( int pos, string &dig, string res, vector<string> &ans ){
        if( pos == dig.size() ) {
            ans.push_back( res );
            return ;
        }
        char from, to;
        if( dig[pos] < '7' ) {
            from = ( dig[pos] - '2' ) * 3 + 'a';
            to = from + 2;
        }
        else if( dig[pos] == '7' ) {
            from = 'p';
            to = 's';
        }
        else if( dig[pos] == '8' ) {
            from = 't';
            to = 'v';
        }
        else from = 'w', to = 'z';
        for( char ch = from; ch <= to; ch ++ ) call( pos+1, dig, res+ch, ans );
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        call( 0, digits, "", res);
        return res;
    }
};
