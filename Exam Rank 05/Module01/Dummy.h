#ifndef MODULE01_DUMMY_H
#define MODULE01_DUMMY_H

#include "ATarget.h"

class Dummy : public ATarget {
private:
    string type;

public:
    Dummy();
    ~Dummy();

    virtual ATarget * clone() const;

};


#endif
