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
        ATarget(ATarget const &other);
        ATarget(std::string const &type);
        virtual ~ATarget();

        std::string const &getType() const;
		void	getHitBySpell(ASpell const &spell) const;
        virtual ATarget *clone() const = 0;
        ATarget &operator=(ATarget const &other);

};

#endif