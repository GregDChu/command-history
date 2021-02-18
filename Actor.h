#pragma once

#include <memory>
#include "Location.h"

class Actor
{
public:
	Actor();
	Actor(std::unique_ptr<Location> location);
	Location& getLocation();
protected:
	std::unique_ptr<Location> location_;
};