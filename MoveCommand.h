#pragma once

#include "Actor.h"
#include "Location.h"
#include "Command.h"

class MoveCommand : public Command
{
public:
	MoveCommand();
	MoveCommand(int xDelta, int yDelta);
	virtual void setSubject(Actor* actor) override;
	virtual void run() override;
	virtual void undo() override;
private:
	Actor* actor_;
	Location startLocation_;
	Location endLocation_;
};