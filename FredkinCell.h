// -------------
// FredkinCell.h
// -------------

#include <vector>
#include <cstdlib>

using namespace std;

class FredkinCell : public AbstractCell {
public:
    static bool is_cell;
    const int num_neighbor = 4;
    const int d_vec[4][2] = { {0,-1}, {-1,0}, {0,1}, {1,0}, {-1,-1}, {-1, 1}, {-1,1}, {1,1} };
    char status;
    size_t age;
    
    FredkinCell() {
        is_cell = true;
        age = 0;
        status = '-';
    }
    
    FredkinCell(char stat) {
        status = stat;
        if (status>='0' && status <='9') {
            age = status - '0';
        }
    }
    
    FredkinCell& update() {
        age += 1;
    }
    
    void die() {
        status = '-';
    }
    
    void resurrect() {
        if (age<10) {
            status = age+'0';
        }else{
            status = '+';
        }
    }
};