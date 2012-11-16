// -------------
// FredkinCell.h
// -------------

#include <vector>
#include <cstdlib>

using namespace std;

class FredkinCell : public AbstractCell {
public:
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
    
    void update() {
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
}