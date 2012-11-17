// ------
// Cell.h
// ------

#include <vector>
#include <cstdlib>

using namespace std;

class Cell {
public:
    static bool is_cell;
    int num_neighbor;
    AbstractCell* ac;
    
    Cell(AbstractCell* that) {
        ac = that;
        num_neighbor = that->num_neighbor;
    }
    
    int get_vec(size_t i, size_t j) {
        return ac->get_vec(i,j);
    }
    
    Cell& operator=(const Cell& that) {
        return *this;
    }
    
    ~Cell() {
        delete ac;
    }
};

bool Cell::is_cell = true;