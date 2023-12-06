#include "ASpell.hpp"

ASpell::ASpell() {}

ASpell::~ASpell() {}

ASpell::ASpell(ASpell &other)
{
    this->name = other.getName();
    this->effects = other.getEffects();
}

ASpell::ASpell(std::string const &name, std::string const &effects)
{
    this->name = name;
    this->effects = effects;
}

ASpell &ASpell::operator=(ASpell const &other)
{
    this->name = other.getName();
    this->effects = other.getEffects();
    return (*this);
}


std::string const &ASpell::getName(void) const
{
    return (this->name);
}


std::string const &ASpell::getEffects(void) const
{
    return (this->effects);
}

void    ASpell::launch(ATarget const &target) const
{
    target.getHitBySpell(*this);
}


