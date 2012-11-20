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
        }else{
            age = 10;
        }
    }
    
    FredkinCell(char stat, size_t new_age) {
        status = stat;
        age = age;
    }
    
    FredkinCell* clone() {
        return new FredkinCell(*this);
    }
    
    int get_vec(size_t i, size_t j) {
        return d_vec[i][j];
    }
    
    FredkinCell* update(size_t neighbor) {
        bool aging = false;
        if (status != '-') {
            aging = true;
        }
        if (neighbor==1 || neighbor==3) {
            size_t new_age = age;
            if (aging==true) {
                new_age += 1;
            }
            char new_stat;
            if (new_age<10) {
                new_stat = new_age+'0';
            }else{
                new_stat = '+';
            }
            return new FredkinCell(new_stat, new_age);
        }else{
            return new FredkinCell('-', age);
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