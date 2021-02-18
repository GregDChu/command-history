#pragma once

#include <string>
#include <iostream>
#include "Attribute.h"

class Location : public Attribute
{
public:
	Location() : x_{ 0 }, y_{ 0 } {};
	Location(int x, int y) : x_{ x }, y_{ y } {};
	int x_;
	int y_;
	const std::string toString() const
	{
		return std::string("(") + std::to_string(x_) + std::string(", ") + std::to_string(y_) + std::string(")");
	}
};