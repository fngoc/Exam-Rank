#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "effects") { }

Fwoosh::~Fwoosh() { }

ASpell *Fwoosh::clone() const { return new Fwoosh(); }
