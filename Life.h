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
    // Life(string fName) {
    //     gen=0;
    //     population=0;
    // }
     Life(std::istream& in)
     {
        gen = 0;
        in >> num_r;
        in >> num_c;

        vector<T> tempSingle(num_r + 2);
        vector<vector<T> > tempBoard(num_c + 2, tempSingle);
        _world1 = tempBoard;

        char c;
        int tempRow;
        int tempCol;

        while(!in.eof())
        {
            while(in.peek() != '\n' && !in.eof())
            {
                in >> c;
                map[tempCol+1][tempRow+1].set(c);
                ++tempCol;
            }
            in.get();//Skips to next line (hopefully)
            ++tempRow;
            tempCol = 0;
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
    
    /**
    * prints board
    */
    void print(){
        printf("Gen: %d, Pop: %d\n", gen, population);
        for(int i = 1; i < cur_world[0].size() - 1; ++i)
        {
            for(int j = 1;  < cur_world.size() - 1; ++j)
            {
                cur_world[j][i].print();
            }
            printf("\n");   
        }
        printf("\n");
    }
};
