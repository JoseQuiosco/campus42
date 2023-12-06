
#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(Warlock const &other) 
{
    *this = other;
}

Warlock &Warlock::operator=(Warlock const &other) 
{
    (void) other;
    return (*this);
}

Warlock::Warlock(std::string const &name, std::string const &title)
{
    this->name = name;
    this->title = title;
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::map<std::string, ASpell *>::iterator it_begin = this->memorized.begin();
    std::map<std::string, ASpell *>::iterator it_end = this->memorized.end();

    while (it_begin != it_end)
    {
       delete  it_begin->second;
       ++it_begin;
    }
    this->memorized.clear();

    std::cout << this->name << ": My job here is done!" << std::endl;
}

std::string const   &Warlock::getName(void) const
{
    return (this->name);
}

std::string const   &Warlock::getTitle(void) const 
{
    return (this->title);
}

void    Warlock::setTitle(std::string const &title)
{
    this->title = title;
}

void    Warlock::introduce(void) const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void    Warlock::learnSpell(ASpell *spell)
{
    if ( spell && this->memorized.find(spell->getName()) == this->memorized.end())
        this->memorized[spell->getName()] = spell->clone();
}

void    Warlock::forgetSpell(std::string const &name)
{
    if (this->memorized.find(name) != this->memorized.end())
    {
        delete this->memorized[name];
        this->memorized.erase(name);
    }
}

void    Warlock::launchSpell(std::string const &spell, ATarget const &target)
{
    if (this->memorized.find(spell) != this->memorized.end())
        this->memorized[spell]->launch(target);
}





