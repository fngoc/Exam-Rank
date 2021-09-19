#include "ASpell.h"

ASpell::ASpell() { }

ASpell::~ASpell() { }

ASpell::ASpell(string name, string effects) : name(name), effects(effects) { }

ASpell::ASpell(const ASpell &aSpell) { *this = aSpell; }

ASpell &ASpell::operator=(const ASpell &aSpell) {
    this->name = aSpell.getName();
    this->effects = aSpell.getEffects();
    return *this;
}

const string &ASpell::getName() const { return name; }

const string &ASpell::getEffects() const { return effects; }

void ASpell::launch(ATarget& aTarget) const { aTarget.getHitBySpell(*this); }
