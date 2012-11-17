// ------------
// ConwayCell.h
// ------------

#include <vector>
#include <cstdlib>

using namespace std;

class ConwayCell : public AbstractCell {
public:
    static bool is_cell;
    const int num_neighbor = 4;
    const int d_vec[4][2] = { {0,-1}, {-1,0}, {0,1}, {1,0} };
    char status;
    
    ConwayCell() {
        status = '.';
    }
    
    ConwayCell(char stat) {
        status = stat;
    }
    
    int get_vec(size_t i, size_t j) {
        return d_vec[i][j];
    }
    
    void update(size_t neighbor) {
        if (neighbor==3) {
            resurrect();
        }else if (neighbor<2 || neighbor>3){
            die();
        }
    }
    
    inline void die() {
        status = '.';
    }
    
    inline void resurrect() {
        status = '*';
    }
};

bool ConwayCell::is_cell = false;