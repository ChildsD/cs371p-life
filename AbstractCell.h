// --------------
// AbstractCell.h
// --------------

#include <vector>
#include <cstdlib>

using namespace std;


class AbstractCell {
public:
    char status;
    virtual void die()=0;
    virtual void resurrect()=0;
}