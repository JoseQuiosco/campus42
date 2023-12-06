
#ifndef __WARLOCK_HPP__
#define __WARLOCK_HPP__

#include <iostream>
#include <string>

class Warlock
{
    private:
        std::string name;
        std::string title;
    
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

};



#endif
