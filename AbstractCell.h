// --------------
// AbstractCell.h
// --------------

#include <vector>
#include <cstdlib>

using namespace std;


class AbstractCell {
public:
    char status;
    const int num_neighbor;
    virtual void die()=0;
    virtual void resurrect()=0;
}