class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int r = matrix.size(); if(!r) return false;
        int c = matrix[0].size(); if(!c) return false;
        
        int lo = 0, hi = r-1;
        while( lo <= hi ){
            int mid = (lo+hi) / 2;
            if( matrix[mid].front() > target ) hi = mid - 1;
            else if( matrix[mid].back() < target ) lo = mid + 1;
            else return binary_search( matrix[mid].begin(), matrix[mid].end(), target );
        }
        
        return false;
    }
};
