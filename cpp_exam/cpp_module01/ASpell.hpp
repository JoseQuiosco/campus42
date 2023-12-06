
#ifndef __A_SPELL_HPP__
#define __A_SPELL_HPP__

#include <iostream>
#include <string>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    protected:
        std::string name;
        std::string effects;
        ASpell();

    public:
        ASpell(ASpell const &other);
        ASpell(std::string const &name, std::string const &effects);
        virtual ~ASpell();

        std::string const &getName() const;
        std::string const &getEffects() const;
		void	launch(ATarget const &target) const;

        virtual ASpell *clone() const = 0;
        ASpell &operator=(ASpell const &other);

};

#endif