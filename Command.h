#pragma once

#include <memory>
#include "Actor.h"

class Command
{
public:
	virtual ~Command() {};
	virtual void setSubject(Actor* actor) = 0;
	virtual void run() = 0;
	virtual void undo() = 0;
};