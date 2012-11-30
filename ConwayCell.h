// ------------
// ConwayCell.h
// ------------

#include <vector>
#include <cstdlib>

using namespace std;

class ConwayCell : public AbstractCell {
public:
    static bool is_cell;
    const static int num_neighbor;
    const static int d_vec[8][2];
    char status;
    
    /*
     * Default constructor
     */
    ConwayCell() {
        status = '.';
    }
    
    /*
     * Constructor
     * @param stat
     *      initial status
     */
    ConwayCell(char stat) {
        if (stat=='*' || stat=='.') {
            status = stat;
        }else{
            throw invalid_argument("invalid status for ConwayCell");
        }
    }
    
    /* Dummy constructor
     */
    ConwayCell(ConwayCell* p) {}
    
    /*
     * @return
     *      number of neighbors need to check
     */
    size_t get_num_neighbor() {
        return num_neighbor;
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
     * Returns a pointer to a new cell for next round
     * @param neighbor
     *      number of alive nighbors
     * @return
     *      pointer to the next round cell
     */
    ConwayCell* update(size_t neighbor) {
        if (neighbor==3) {
            return new ConwayCell('*');
        }else if (neighbor<2 || neighbor>3){
            return new ConwayCell('.');
        }
        return new ConwayCell(*this);
    }
    
    /*
     * @return
     *      current status
     */
    char get_status() {
        return status;
    }
    /*
     * Destructor
     */
    ~ConwayCell(){}
};

const int ConwayCell::num_neighbor = 8;
bool ConwayCell::is_cell = false;
const int ConwayCell::d_vec[8][2] = { {0,-1}, {-1,0}, {0,1}, {1,0}, {-1,-1}, {1, -1}, {-1,1}, {1,1} };