class Solution {
public:
    int gcd( int a, int b ) {
        if( a < 0 ) return gcd( -a, b );
        if( b < 0 ) return gcd( a, -b );
        if( !a ) return b;
        return gcd( b%a , a );
    }
    void getLine( Point p, Point q, int &a, int &b, int &c ) {
        a = p.y - q.y;
        b = q.x - p.x;
        c = p.x * q.y - q.x * p.y;
        int g = gcd( a, gcd( b, c ) );
        if( !g ) return ;
        a /= g;
        b /= g;
        c /= g;
        if( a < 0 || ( !a && b < 0 ) ) a = -a, b = -b, c = -c;
    }

    int maxPoints(vector<Point> &points) {
        int n  = points.size();
        if( n < 2 ) return n;

        int ret = 0;

        for( int i = 0; i < n; i++ ) {

            unordered_map< int , unordered_map< int , unordered_map< int , int > > > ase;

            int maxi = 0;
            int self = 0;

            for( int j = i; j < n; j++ ) {
                if( points[j].x == points[i].x && points[j].y == points[i].y ) {
                    self++;
                    continue;
                }
                int a, b, c;
                getLine( points[i], points[j], a, b, c );
                ase[a][b][c]++;
                maxi = max( maxi , ase[a][b][c] );
            }

            ret = max( ret , maxi + self );
        }

        return ret;
    }
};
