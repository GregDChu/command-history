#pragma once

#include <string>

class Location;

class DefaultMessages
{
public:
	static const std::string getCommands();
	static const std::string formatLocation(const Location& location);
};