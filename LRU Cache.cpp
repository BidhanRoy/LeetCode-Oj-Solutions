class LRUCache{

    typedef list<int>:: iterator listIterator;
    typedef unordered_map< int , pair< int , listIterator > > :: iterator mapIterator;

    int capacity;
    list< int > pool;
    unordered_map< int , pair< int , listIterator > > Map;

    void makeRecent( mapIterator it ) {
        pool.erase( it->second.second );
        pool.push_back( it->first );
        listIterator itP = pool.end();
        itP--;
        it->second.second = itP;
    }

    void reduce() {
        listIterator it = pool.begin();
        Map.erase( *it );
        pool.erase( it );
    }

public:

    LRUCache(int _capacity) {
        capacity = _capacity;
    }

    int get(int key) {
        mapIterator it = Map.find( key );
        if( it == Map.end() ) return -1;
        makeRecent( it );
        return it->second.first;
    }

    void set(int key, int value) {
        mapIterator it = Map.find( key );
        if( it == Map.end() ) {
            pool.push_back( key );
            auto itP = pool.end(); itP--;
            Map[ key ] = { value, itP };

            if( (int)pool.size() > capacity ) reduce();

            return ;
        }
        it->second.first = value;
        makeRecent( it );
    }
};
