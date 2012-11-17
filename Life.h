// ------
// Life.h
// ------

#include <vector>
#include <cstdlib>

using namespace std;

template<typename T>
class Life {
    typedef vector< vector<T*> >* worldPtr;
    vector< vector<T*> > _world1;
    vector< vector<T*> > _world2;
    worldPtr cur_world;
    worldPtr next_world;
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
        
        vector<T> row(c, NULL);
        vector<vector<T> > world(r, row);
        _world = world;
        num_r = r;
        num_c = c;
        turn = 0;
    }
    
    
    
    void run(size_t num_turns) {
        if (T.is_cell) {
        }
        
        int next_r;
        int next_c;
        for (int turn=0; turn<num_turns; ++turn) {
            for (int r=0; r<num_r; ++r) {
                for (int c=0; c<num_c; ++c) {
                    //reference to current cell
                    T& cur_cell = (*cur_world)[r][c];
                    
                    //go through each in-bound neighbor and count the number of alive ones
                    int alive_cnt = 0;
                    for (int i=0; i<cur_cell.num_neighbor; ++i) {
                        next_r = r + cur_cell.d_vec[i][0];
                        next_c = c + cur_cell.d_vec[i][2];
                        if (in_bound(next_r, next_c)) {
                            if ((*cur_world)[next_r][next_c].status!='.' && (*cur_world)[next_r][next_c].status!='-') {
                                alive_cnt += 1;
                            }
                        }
                    }
                    
                    //update according to how many alive neighbors exist
                    cur_cell.update(alive_cnt);
                    
                }
            }
            
            //at the end of each turn, swap pointers to worlds
            worldPtr temp = cur_world;
            cur_world = next_world;
            next_world = cur_world;
        }
        
        
    }
    
};
