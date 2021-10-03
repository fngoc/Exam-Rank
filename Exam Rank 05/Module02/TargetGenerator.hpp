#ifndef MODULE02_TARGETGENERATOR_HPP
#define MODULE02_TARGETGENERATOR_HPP

#include <vector>
#include "ATarget.hpp"

using std::vector;

class TargetGenerator {
private:
    vector<ATarget *> arr;

    TargetGenerator(const TargetGenerator& targetGenerator);
    TargetGenerator& operator=(const TargetGenerator& targetGenerator);

public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget*);
    void forgetTargetType(string const &);
    ATarget* createTarget(string const &);
};

#endif
