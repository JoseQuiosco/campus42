#include "ATarget.hpp"

ATarget::ATarget(ATarget const &other)
{
	this->type = other.getType();
}

ATarget::ATarget(std::string const &type)
{
	this->type = type;
}

ATarget::~ATarget() {}

std::string const &ATarget::getType() const
{
	return (this->type);
}

void	ATarget::getHitBySpell(ASpell const &spell) const
{
	std::cout << this->type << " has been " << spell.getEffects() << std::endl;
}


ATarget &ATarget::operator=(ATarget const &other)
{
	this->type = other.getType();
	return (*this);
}
