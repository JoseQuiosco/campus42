
#ifndef __WARLOCK_HPP__
#define __WARLOCK_HPP__

#include <iostream>
#include <string>
#include <map>
#include "ASpell.hpp"
#include "ATarget.hpp"

class ASpell;
class ATarget;

class Warlock
{
    private:
        std::string name;
        std::string title;
    
        std::map<std::string , ASpell *>   memorized;

        Warlock &operator=(Warlock const &other);
        Warlock();
        Warlock(Warlock const &other);

    public:
        Warlock(std::string const &name, std::string const &title);
        ~Warlock();

        std::string const   &getName(void) const;
        std::string const   &getTitle(void) const;
        void                setTitle(std::string const &title);
        void                introduce(void) const;
        
        void                learnSpell(ASpell *spell);
        void                forgetSpell(std::string const &name);
        void                launchSpell(std::string const &spell, ATarget const &target); 
};



#endif
