#ifndef MODULE02_BRICKWALL_HPP
#define MODULE02_BRICKWALL_HPP

#include "ATarget.hpp"

class BrickWall : public ATarget {
private:
    string type;

public:
    BrickWall();
    ~BrickWall();

    virtual ATarget * clone() const;
};

#endif
