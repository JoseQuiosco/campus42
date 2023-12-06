#include "TargetGenerator.hpp"


TargetGenerator::TargetGenerator()
{}

TargetGenerator::~TargetGenerator()
{
	std::map<std::string, ATarget *>::iterator it_begin = this->targets.begin();
	std::map<std::string, ATarget *>::iterator it_final = this->targets.end();
	while (it_begin != it_final)
	{
		delete it_begin->second;
		it_begin++;
	}
	this->targets.clear();
}

void TargetGenerator::learnTargetType(ATarget *target)
{
	if (target && (this->targets.find(target->getType()) == this->targets.end()))
	{
		this->targets.insert(std::pair<std::string, ATarget *>(target->getType(), target->clone()));
	}
}

void TargetGenerator::forgetTargetType(std::string const &type)
{
	if ((this->targets.find(type) != this->targets.end()))
	{
		delete this->targets[type];
		this->targets.erase(type);
	}
}


ATarget* TargetGenerator::createTarget(std::string const &type)
{
	if (this->targets.find(type) != this->targets.end())
		return this->targets[type];
	return NULL;
}
