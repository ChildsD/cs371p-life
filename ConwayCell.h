// ------------
// ConwayCell.h
// ------------

#include <vector>
#include <cstdlib>

using namespace std;

class ConwayCell : public AbstractCell {
public:
    char status;
    static bool is_cell;
    const int num_neighbor = 4;
    const int d_vec[8][2] = { {0,-1}, {-1,0}, {0,1}, {1,0} };
    
    ConwayCell() {
        is_cell = false;
        status = '.';
    }
    
    ConwayCell(char stat) {
        status = stat;
    }
    
    ConwayCell& update(size_t alive_neighbor) {
        
    }
    
    inline void die() {
        status = '.';
    }
    
    inline void resurrect() {
        status = '*';
    }
};
