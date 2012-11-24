// ------------
// ConwayCell.h
// ------------

#include <vector>
#include <cstdlib>

using namespace std;

class ConwayCell : public AbstractCell {
public:
    static bool is_cell;
    const static int num_neighbor;
    const static int d_vec[8][2];
    char status;
    
    ConwayCell() {
        status = '.';
    }
    
    ConwayCell(char stat) {
        status = stat;
    }
    
    ConwayCell* clone() {
        return new ConwayCell(*this);
    }
    
    int get_vec(size_t i, size_t j) {
        return d_vec[i][j];
    }
    
    ConwayCell* update(size_t neighbor) {
        if (neighbor==3) {
            return new ConwayCell('*');
        }else if (neighbor<2 || neighbor>3){
            return new ConwayCell('.');
        }
        return new ConwayCell(*this);
    }
    
    char get_status() {
        return status;
    }
    
    inline void die() {
        status = '.';
    }
    
    inline void resurrect() {
        status = '*';
    }
    
    ~ConwayCell(){}
};

const int ConwayCell::num_neighbor = 8;
bool ConwayCell::is_cell = false;
const int ConwayCell::d_vec[8][2] = { {0,-1}, {-1,0}, {0,1}, {1,0}, {-1,-1}, {1, -1}, {-1,1}, {1,1} };