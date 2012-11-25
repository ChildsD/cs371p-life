// ------
// Life.h
// ------

#include <vector>
#include <cstdlib>
#include <fstream>

using namespace std;

template<typename T>
class Life {
    typedef vector< vector<T*> > World;
    typedef World* p_World;
    
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
    Life(ifstream& infile) {
        gen=0;
        population=0;
        
        string line;
        getline(infile, line);
        num_r = atoi(line.c_str());
        getline(infile, line);
        num_c = atoi(line.c_str());
        
        vector<T*> row(num_c, 0);
        cur_world = new World(num_r, row);
        next_world = new World(num_r, row);
        
        for (size_t r=0; r<num_r; ++r) {
            getline(infile, line);
            for (size_t c=0; c<num_c; ++c) {
                (*cur_world)[r][c] = new T(line.at(c));
                if (!(line.at(c)=='-' || line.at(c)=='.')) {
                    population += 1;
                }
            }
        }
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
        size_t num_neighbor = 0;
        for (size_t turn=0; turn<num_turns; ++turn) {
            population = 0;
            for (int r=0; (size_t) r<num_r; ++r) {
                for (int c=0; (size_t) c<num_c; ++c) {
                    
                    //reference to current cell
                    T& cur_cell = *(*cur_world)[r][c];
                    
                    //go through each in-bound neighbor and count the number of alive ones
                    int alive_cnt = 0;
                    //cout << r << "x" << c << " neighbors are ";
                    num_neighbor = cur_cell.get_num_neighbor();
                    for (size_t i=0; i<num_neighbor; ++i) {
                        next_r = r + cur_cell.get_vec(i, 0);
                        next_c = c + cur_cell.get_vec(i, 1);
                        if (in_bound(next_r, next_c)) {
                            if ((*cur_world)[next_r][next_c]->get_status()!='.' && (*cur_world)[next_r][next_c]->get_status()!='-') {
                                alive_cnt += 1;
                            }
                        }
                    }
                    //cout << endl;
                    
                    //check if this cell can potentially mutate
                    if (T::is_cell && cur_cell.get_status()=='1') {
                        fred_mutate = true;
                    }
                    //update according to how many alive neighbors exist
                    delete (*next_world)[r][c];
                    (*next_world)[r][c] = cur_cell.update(alive_cnt);
                    
                    //check if this cell is supposed to mutate
                    if (fred_mutate && (*next_world)[r][c]->get_status()=='2') {
                        //mutate to a live conway
                        delete (*next_world)[r][c];
                        (*next_world)[r][c] = new T(new ConwayCell('*'));
                    }
                    
                    //count the number of population
                    if (!((*next_world)[r][c]->get_status()=='-' || (*next_world)[r][c]->get_status()=='.')) {
                        population += 1;
                    }
                    alive_cnt = 0;
                    fred_mutate = false;
                }
            }
            gen+=1;
            //at the end of each turn, swap pointers to worlds
            p_World temp = cur_world;
            cur_world = next_world;
            next_world = temp;
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
                w << (*cur_world)[i][j]->get_status();
            }
            w << endl;
        }
        w << endl;
    }
    
    ~Life() {
        for (int r=0; (size_t) r<num_r; ++r) {
            for (int c=0; (size_t) c<num_c; ++c) {
                delete (*cur_world)[r][c];
            }
        }
        for (int r=0; (size_t) r<num_r; ++r) {
            for (int c=0; (size_t) c<num_c; ++c) {
                delete (*next_world)[r][c];
            }
        }
        delete cur_world;
        delete next_world;
    }
};
