// --------------
// AbstractCell.h
// --------------

#include <vector>
#include <cstdlib>

using namespace std;


class AbstractCell {
public:
    char status;
    const int num_neighbor=0;
    virtual void die()=0;
    virtual void resurrect()=0;
    virtual void update(size_t neighbor)=0;
    virtual int get_vec(size_t i, size_t j)=0;
    virtual ~AbstractCell()=0;
};