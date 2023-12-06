
#include "SpellBook.hpp"


SpellBook::SpellBook()
{}

SpellBook::~SpellBook()
{
	std::map<std::string, ASpell *>::iterator it_begin = this->book.begin();
	std::map<std::string, ASpell *>::iterator it_final = this->book.end();
	while (it_begin != it_final)
	{
		delete it_begin->second;
		it_begin++;
	}
	this->book.clear();
}

void SpellBook::learnSpell(ASpell* spell)
{
	if (spell && (this->book.find(spell->getName()) == this->book.end()))
	{
		this->book.insert(std::pair<std::string, ASpell *>(spell->getName(), spell->clone()));
	}
}

void SpellBook::forgetSpell(std::string const &spellname)
{
	if ((this->book.find(spellname) != this->book.end()))
	{
		delete this->book[spellname];
		this->book.erase(spellname);
	}
}


ASpell* SpellBook::createSpell(std::string const &spellname)
{
	if (this->book.find(spellname) != this->book.end())
		return this->book[spellname];
	return NULL;
}