#ifndef MODULE01_DUMMY_HPP
#define MODULE01_DUMMY_HPP

#include "ATarget.hpp"

class Dummy : public ATarget {
private:
    string type;

public:
    Dummy();
    ~Dummy();

    virtual ATarget * clone() const;
};

#endif
