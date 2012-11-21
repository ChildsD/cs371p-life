// ------
// Cell.h
// ------

#include <vector>
#include <cstdlib>

using namespace std;

class Cell {
public:
    static bool is_cell;
    int num_neighbor;
    AbstractCell* ac;
    
    Cell(AbstractCell* that) {
        ac = that;
        num_neighbor = that->num_neighbor;
    }
    
    int get_vec(size_t i, size_t j) {
        return ac->get_vec(i,j);
    }
    
    AbstractCell* update(size_t neighbor) {
        return ac->update(neighbor);
    }
    
    Cell& operator=(const Cell& that) {
        return *this;
    }
    
    ~Cell() {
        delete ac;
    }

    //See the print method below for details, but because I was planning
    //on ac being generic, this calls the set method of whatever SPECIFIC
    //cell we're dealing with
    void set(char c)
    {
        if(c!='*' && c!='.')
        {
            ac -> set(c);
        }

        else
        {
            delete ac;
            ac = new ConwayCell();
            ac -> set(c);
        }
    }

    void print()
    {
        //This might give us problems because when I wrote it I was assuming
        //that 'ac' would be type T*, not AbstractCell*. This call (at least
        //as I intended it) relies on each type of cell having its own, unique
        //print method
        ac -> print();
    }
};

bool Cell::is_cell = true;