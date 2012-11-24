// --------------
// AbstractCell.h
// --------------

#include <vector>
#include <cstdlib>

using namespace std;


class AbstractCell {
public:
    virtual AbstractCell* update(size_t neighbor)=0;
    virtual int get_vec(size_t i, size_t j)=0;
    virtual char get_status()=0;
    virtual size_t get_num_neighbor()=0;
    virtual ~AbstractCell()=0;
};

AbstractCell::~AbstractCell() {}
