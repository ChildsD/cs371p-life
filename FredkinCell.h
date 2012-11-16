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
        status = '-';
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