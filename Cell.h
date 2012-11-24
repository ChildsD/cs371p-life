// ------
// Cell.h
// ------

#include <vector>
#include <cstdlib>

using namespace std;

class Cell {
public:
    static bool is_cell;
    size_t num_neighbor;
    AbstractCell* ac;
    
    Cell(AbstractCell* that) {
        ac = that;
        num_neighbor = that->get_num_neighbor();
    }
    
    Cell(char stat) {
        if (stat == '.' || stat == '*') {
            ac = new ConwayCell(stat);
        }else{
            ac = new FredkinCell(stat);
        }
    }
    
    char get_status() {
        return ac->get_status();
    }
    
    size_t get_num_neighbor() {
        return ac->get_num_neighbor();
    }
    
    int get_vec(size_t i, size_t j) {
        return ac->get_vec(i,j);
    }
    
    Cell* update(size_t neighbor) {
        return new Cell(ac->update(neighbor));
    }
    
    Cell& operator=(const Cell& that) {
        return *this;
    }
    
    Cell& operator=(AbstractCell* that) {
        ac = that;
        return *this;
    }
    
    ~Cell() {
        delete ac;
    }
};

bool Cell::is_cell = true;