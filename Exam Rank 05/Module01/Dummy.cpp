#include "Dummy.h"

Dummy::Dummy() : type("Target Practice Dummy") { }

Dummy::~Dummy() { }

ATarget *Dummy::clone() const { return new Dummy(); }
