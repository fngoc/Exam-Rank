#include "ATarget.hpp"

ATarget::ATarget() { }

ATarget::~ATarget() { }

ATarget::ATarget(const ATarget &aTarget) { *this = aTarget; }

ATarget &ATarget::operator=(const ATarget &aTarget) {
    this->type = aTarget.getType();
    return *this;
}

const string &ATarget::getType() const { return type; }

ATarget::ATarget(string type) : type(type) { }

void ATarget::getHitBySpell(const ASpell &aSpell) const { cout << this->type << " has been " << aSpell.getEffects() << "!" << endl; }
