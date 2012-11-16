// ------
// Cell.h
// ------

#include <vector>
#include <cstdlib>

using namespace std;

class Cell {
    
    AbstractCell* ac;
    
    Cell(AbstractCell* that) {
        ac = that;
    }
    
    Cell& operator=(const Cell& that) {
        ac = new AbstractCell();
    }
    
}