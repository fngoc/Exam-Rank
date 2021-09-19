#include "Fwoosh.h"

Fwoosh::Fwoosh() : name("Fwoosh"), effects("effects") { }

Fwoosh::~Fwoosh() { }

ASpell *Fwoosh::clone() const { return new Fwoosh(); }
