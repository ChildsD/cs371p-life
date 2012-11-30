// ------
// Cell.h
// ------

#include <vector>
#include <cstdlib>

using namespace std;

class Cell {
public:
    static bool is_cell;
    size_t num_neighbor;
    AbstractCell* ac;
    
    /*
     * Constructor
     * @param that
     *      pointer to source object
     */
    Cell(AbstractCell* that) {
        ac = that;
        num_neighbor = that->get_num_neighbor();
    }
    
    /*
     * Constructor
     * @param stat
     *      initial status
     */
    Cell(char stat) {
        if (stat == '.' || stat == '*') {
            ac = new ConwayCell(stat);
        }else{
            ac = new FredkinCell(stat);
        }
    }
    
    /*
     * @return
     *      current status
     */
    char get_status() {
        return ac->get_status();
    }
    
    /*
     * @return
     *      number of neighbors need to check
     */
    size_t get_num_neighbor() {
        return ac->get_num_neighbor();
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
        return ac->get_vec(i,j);
    }
    
    /*
     * Returns a pointer to a new cell for next round
     * @param neighbor
     *      number of alive nighbors
     * @return
     *      pointer to the next round cell
     */
    Cell* update(size_t neighbor) {
        return new Cell(ac->update(neighbor));
    }
    
    /*
     * Assignment
     * @param that
     *      source
     */
    Cell& operator=(const Cell& that) {
        return *this;
    }
    
    /*
     * Assignment
     * @param that
     *      source
     */
    Cell& operator=(AbstractCell* that) {
        ac = that;
        return *this;
    }
    
    /*
     * Destructor
     */
    ~Cell() {
        delete ac;
    }
};

bool Cell::is_cell = true;