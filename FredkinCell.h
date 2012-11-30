// -------------
// FredkinCell.h
// -------------

#include <vector>
#include <cstdlib>

using namespace std;

class FredkinCell : public AbstractCell {
public:
    static bool is_cell;
    static const int num_neighbor;
    static const int d_vec[4][2];
    char status;
    size_t age;
    
    /* 
     * Default constructor
     */
    FredkinCell() {
        age = 0;
        status = '-';
    }
    
    /*
     * Constructor
     * @param stat
     *      initial status
     */
    FredkinCell(char stat) {
        status = stat;
        if (status>='0' && status <='9') {
            age = status - '0';
        }else if (status=='-'){
            age = 0;
        }else if (status=='+'){
            age = 10;
        }else{
            throw invalid_argument("invalid status for FredkinCell");
        }
    }
    
    /*
     * Constructor
     * @param stat
     *      initial status
     * @param new_age
     *      initial age
     */
    FredkinCell(char stat, size_t new_age) {
        status = stat;
        age = new_age;
    }
    
    /*
     * Returns a value of the delta vector at a specified location
     * @param i
     *      pair index
     * @param j
     *      number index
     * @return
     *      delta value
     */
    int get_vec(size_t i, size_t j) {
        return d_vec[i][j];
    }
    
    /*
     * @return
     *      number of neighbors need to check
     */
    size_t get_num_neighbor() {
        return num_neighbor;
    }
    
    /*
     * @return
     *      current status
     */
    char get_status() {
        return status;
    }
    
    /* Dummy constructor
     */
    FredkinCell(ConwayCell* p) {}
    
    /*
     * Returns a pointer to a new cell for next round
     * @param neighbor
     *      number of alive nighbors
     * @return
     *      pointer to the next round cell
     */
    FredkinCell* update(size_t neighbor) {
        bool aging = false;
        if (status != '-') {
            aging = true;
        }
        if (neighbor==1 || neighbor==3) {
            size_t new_age = age;
            char new_stat;
            
            if (aging==true) {
                new_age += 1;
            }
            if (new_age<10) {
                new_stat = new_age+'0';
            }else{
                new_stat = '+';
            }
            return new FredkinCell(new_stat, new_age);
        }else{
            return new FredkinCell('-', age);
        }
    }
    /*
     * Destructor
     */
    ~FredkinCell() {}
};
const int FredkinCell::num_neighbor = 4;
bool FredkinCell::is_cell = false;
const int FredkinCell::d_vec[4][2] = { {0,-1}, {-1,0}, {0,1}, {1,0} };