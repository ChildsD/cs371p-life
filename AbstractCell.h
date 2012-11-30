// --------------
// AbstractCell.h
// --------------

#include <vector>
#include <cstdlib>

using namespace std;

/* Parent class for specialized cell classes */

class AbstractCell {
public:
    /*
     * Returns a pointer to a new cell for next round
     * @param neighbor
     *      number of alive nighbors
     * @return
     *      pointer to the next round cell
     */
    virtual AbstractCell* update(size_t neighbor)=0;
    /*
     * Returns a value of the delta vector at a specified location
     * @param i
     *      pair index
     * @param j
     *      number index
     * @return
     *      delta value
     */
    virtual int get_vec(size_t i, size_t j)=0;
    /*
     * @return
     *      current status
     */
    virtual char get_status()=0;
    /*
     * @return
     *      number of neighbors need to check
     */
    virtual size_t get_num_neighbor()=0;
    /*
     * Destructor
     */
    virtual ~AbstractCell()=0;
};

AbstractCell::~AbstractCell() {}
