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
    const int d_vec[8][2] = { {0,-1}, {-1,0}, {0,1}, {1,0}, {-1,-1}, {-1, 1}, {-1,1}, {1,1} };
    char status;
    size_t age;
    
    FredkinCell() {
        age = 0;
        status = '-';
    }
    
    FredkinCell(char stat) {
        status = stat;
        if (status>='0' && status <='9') {
            age = status - '0';
        }
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

bool FredkinCell::is_cell = false;