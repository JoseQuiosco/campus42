
#ifndef __BRICK_WALL_HPP__
#define __BRICK_WALL_HPP__

#include "ATarget.hpp"

class BrickWall : public ATarget
{
    public:
		BrickWall();
		~BrickWall();
		ATarget *clone() const;
};

#endif