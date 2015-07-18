class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        reverse( digits.begin(), digits.end() );
        int carry = 1;
        for( int i = 0; i < (int) digits.size(); i++ ) {
            int now = digits[i] + carry;
            digits[i] = now % 10;
            carry = now / 10;
        }
        if( carry ) digits.push_back( carry );
        reverse( digits.begin(), digits.end() );
        return digits;
    }
};
