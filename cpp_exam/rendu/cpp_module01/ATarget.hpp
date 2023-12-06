#ifndef __A_TARGET_HPP__
#define __A_TARGET_HPP__

#include <iostream>
#include <string>
#include "ASpell.hpp"


class ASpell;

class ATarget
{
    protected:
        std::string type;
        ATarget();

    public:
        
        ATarget(ATarget &other);
        ATarget(std::string const &type);
        virtual ~ATarget();
        
        std::string const &getType(void) const;

        virtual ATarget *clone(void) const  = 0;

        void getHitBySpell(ASpell const &spell) const;

        ATarget &operator=(ATarget const &other);
};







#endif
