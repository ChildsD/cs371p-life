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
    const int d_vec[4][2] = { {0,-1}, {-1,0}, {0,1}, {1,0} };
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
        bool aging = false;
        if (status != '-') {
            aging = true;
        }
        if (neighbor==1 || neighbor==3) {
            resurrect();
        }else{
            die();
        }
        if (aging && status != '-') {
            age += 1;
            if (age<10) {
                status = age + '0';
            }
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