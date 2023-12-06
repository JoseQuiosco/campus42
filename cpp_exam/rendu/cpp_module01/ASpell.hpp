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
        
        ASpell(ASpell &other);
        ASpell(std::string const &name, std::string const &effects);
        virtual ~ASpell();
        
        std::string const &getName(void) const;
        std::string const &getEffects(void) const;

        virtual ASpell *clone(void) const  = 0;

        void    launch(ATarget const &target) const;

        ASpell &operator=(ASpell const &other);
};







#endif
