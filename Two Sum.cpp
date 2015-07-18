class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        unordered_map< int , int > hashMap;
        
        int n = numbers.size();
        
        vector< int > ret;
        
        for( int i = 0; i < n; i++ ) {
            int now = numbers[i];
            int other = target - now;
            if( hashMap.count( other ) > 0 ) {
                ret.push_back( hashMap[ other ] + 1 );
                ret.push_back( i + 1 );
                break;
            }
            hashMap[ now ] = i;
        }
        
        return ret;
    }
};
