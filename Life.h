// ------
// Life.h
// ------

#include <vector>
#include <cstdlib>

using namespace std;

template<typename T>
class Life {
    typedef vector< vector<T*> > World;
    typedef World* p_World;
    
    World _world1;
    World _world2;
    p_World cur_world;
    p_World next_world;
    size_t num_r;
    size_t num_c;
    size_t gen;
    size_t population;
    
public:
    /*
     * Constructor
     * @param fName
     *    Name of the input file
     */
    Life(string fName) {
        gen=0;
        population=0;
    }

    /*
     * Check if the location specified by input coordinates is in bound
     * @param r
     *     row coordinate of the location
     * @param c
     *     col coordinate of the location
     */
    bool in_bound(int r, int c) {
        return r>=0 && (unsigned int)r<num_r && c>=0 && (unsigned int)c<num_c;
    }
    
    void run(size_t num_turns) {
        if (T::is_cell) {
        }
        
        int next_r = 0;
        int next_c = 0;
        bool fred_mutate = false;
        
        for (int turn=0; turn<num_turns; ++turn) {
            population = 0;
            for (int r=0; r<num_r; ++r) {
                for (int c=0; c<num_c; ++c) {
                    //reference to current cell
                    T& cur_cell = (*cur_world)[r][c];
                    if (!((*next_world)[r][c].status=='-' || (*next_world)[r][c].status=='.')) {
                        population += 1;
                    }
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
                    
                    //check if this cell can potentially mutate
                    if (T::is_cell) {
                        if (cur_cell.status=='1') {
                            fred_mutate = true;
                        }
                    }
                    //update according to how many alive neighbors exist
                    (*next_world)[r][c] = cur_cell.update(alive_cnt);
                    //check if this cell 
                    if (fred_mutate && cur_cell.status=='2') {
                        //change cur_cell to a conway
                    }
                }
                gen+=1;
            }
            
            //at the end of each turn, swap pointers to worlds
            p_World temp = cur_world;
            cur_world = next_world;
            next_world = cur_world;
        }
    }
    
    /*
     * Print the grid
     * @param w
     *      ostream to print to
     */
    void print(std::ostream& w) {
        w << "Generation = " << gen << ", Population = " << population << ".";
        w << endl;
        for (size_t i=0; i<num_r; ++i) {
            for (size_t j=0; j<num_c; ++j) {
                w << (*cur_world)[i][j].status;
            }
            w << endl;
        }
        w << endl;
    }
};
