// ------------
// ConwayCell.h
// ------------

#include <vector>
#include <cstdlib>

using namespace std;

class ConwayCell : public AbstractCell {
public:
    char status;
    
    ConwayCell() {
        status = '.';
    }
    
    ConwayCell(char stat) {
        status = stat;
    }
    
    void update(size_t alive_neighbor) {
        
    }
    
    inline void die() {
        status = '.';
    }
    
    inline void resurrect() {
        status = '*';
    }
}