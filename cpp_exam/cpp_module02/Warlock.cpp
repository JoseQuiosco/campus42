#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() 
{
	std::cout << this->name << ": My job here is done!\n";
}

std::string const &Warlock::getName() const 
{ 
	return (this->name);
}

std::string const &Warlock::getTitle() const 
{
	return (this->title);
}

void Warlock::setTitle(std::string const &title) 
{ 
	this->title = title;
}

void Warlock::introduce() const 
{
	std::cout << this->name << ": I am " << this->name << ", " << this->title << "!\n";
}

void Warlock::learnSpell(ASpell *spell)
{
	if (spell)
	{
		this->book.learnSpell(spell);
	}
}

void Warlock::forgetSpell(std::string spellname)
{
	this->book.forgetSpell(spellname);
}

void Warlock::launchSpell(std::string spell, ATarget const &target)
{
	ASpell *aspell;
	
	aspell = this->book.createSpell(spell);
	if (aspell)
		aspell->launch(target);
}
