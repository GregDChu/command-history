#include "Actor.h"

Actor::Actor() :
	location_{ std::make_unique<Location>() }
{
}

Actor::Actor(std::unique_ptr<Location> location) :
	location_{ std::move(location) }
{}

Location& Actor::getLocation()
{
	return *location_.get();
}
