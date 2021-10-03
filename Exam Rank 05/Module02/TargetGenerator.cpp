#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() { }

TargetGenerator::~TargetGenerator() {
    vector<ATarget *>::iterator it_begin = this->arr.begin();
    vector<ATarget *>::iterator it_end = this->arr.end();

    while (it_begin != it_end)
    {
        delete (*it_begin);
        ++it_begin;
    }
    this->arr.clear();
}

void TargetGenerator::learnTargetType(ATarget *aTarget) {
    vector<ATarget *>::iterator it_begin = this->arr.begin();
    vector<ATarget *>::iterator it_end = this->arr.end();

    if (aTarget)
    {
        while (it_begin != it_end)
        {
            if ((*it_begin)->getType() == aTarget->getType())
                return ;
            ++it_begin;
        }
        this->arr.push_back(aTarget->clone());
    }
}

void TargetGenerator::forgetTargetType(const string &name) {
    vector<ATarget *>::iterator it_begin = this->arr.begin();
    vector<ATarget *>::iterator it_end = this->arr.end();

    while (it_begin != it_end)
    {
        if ((*it_begin)->getType() == name)
        {
            delete *it_begin;
            this->arr.erase(it_begin);
            return ;
        }
        ++it_begin;
    }
}

ATarget *TargetGenerator::createTarget(const string &name) {
    vector<ATarget *>::iterator it_begin = this->arr.begin();
    vector<ATarget *>::iterator it_end = this->arr.end();

    while (it_begin != it_end)
    {
        if ((*it_begin)->getType() == name)
            return (*it_begin);
        ++it_begin;
    }
    return (NULL);
}
