#ifndef __TARGET_GENERATOR__
#define __TARGET_GENERATOR__

#include "ATarget.hpp"
#include <iostream>
#include <string>
#include <map>

class ATarget;

class TargetGenerator
{
	private:

		std::map<std::string, ATarget *> targets;

							TargetGenerator(TargetGenerator const &TargetGenerator);
		TargetGenerator 	&operator=(TargetGenerator const &TargetGenerator);
	
	public:
					TargetGenerator();
					~TargetGenerator();
		void 		learnTargetType(ATarget *target);
		void 		forgetTargetType(std::string const &type);
        ATarget		*createTarget(std::string const &type);
};


#endif

/*
* void learnTargetType(ATarget*), teaches a target to the generator

* void forgetTargetType(string const &), that makes the generator forget a
  target type if it's known

* ATarget* createTarget(string const &), that creates a target of the
  specified type

*/