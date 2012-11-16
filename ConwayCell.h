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
    
    void die() {
        status = '.';
    }
    
    void resurrect() {
        status = '*';
    }
}