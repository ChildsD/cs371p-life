// ------
// Life.h
// ------

#include <vector>
#include <cstdlib>

using namespace std;

template<typename T>
class Life {
    vector< vector<Cell*> > _world1;
    vector< vector<Cell*> > _world2;
    deque<creature> life_list;
    size_t num_r;
    size_t num_c;
    size_t turn;
    
    /*
     * get a pointer to the content of one location
     * @param x
     *     row coordinate of the location
     * @param y
     *     col coordinate of the location
     * @return
     *     a pointer to the creature instance at the specified location; if the location is empty, it's NULL
     */
    creature* get_content(size_t x, size_t y) {
        return _world[x][y];
    }
    
public:
    /*
     * Constructor
     * @param r
     *     number of rows in this world
     * @param c
     *     number of columns in this world
     */
    Darwin(size_t r, size_t c) {
        vector<creature*> row(c, NULL);
        vector<vector<creature*> > world(r, row);
        _world = world;
        num_r = r;
        num_c = c;
        turn = 0;
    }
    
    
};

