#include "Warlock.hpp"

Warlock::Warlock(std::string const &name, std::string const &title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day.\n";
}

Warlock::~Warlock() 
{
	std::map<std::string, ASpell *>::iterator it_begin = this->memorized.begin();
    std::map<std::string, ASpell *>::iterator it_end = this->memorized.end();
    while (it_begin != it_end)
    {
        delete it_begin->second;
        ++it_begin;
    }
    this->memorized.clear();
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
	if (spell && (this->memorized.find(spell->getName()) == this->memorized.end()))
	{
		this->memorized[spell->getName()] = spell->clone();
	}
}

void Warlock::forgetSpell(std::string spellname)
{
	if ((this->memorized.find(spellname) != this->memorized.end()))
	{
		delete this->memorized[spellname];
		this->memorized.erase(spellname);
	}
}

void Warlock::launchSpell(std::string spell, ATarget const &target)
{
	ASpell *aspell;
	if (this->memorized.find(spell) != this->memorized.end())
	{
		aspell = this->memorized[spell];
		aspell->launch(target);
	}
}
