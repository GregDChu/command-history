#include "MoveCommand.h"

MoveCommand::MoveCommand() :
	actor_{nullptr},
	startLocation_{0, 0},
	endLocation_{0, 0}
{}

MoveCommand::MoveCommand(int xDelta, int yDelta) :
	actor_{nullptr},
	startLocation_{0, 0},
	endLocation_{xDelta, yDelta}
{}

void MoveCommand::setSubject(Actor* actor)
{
	if (!actor_)
	{
		actor_ = actor;
		Location& location = actor_->getLocation();
		startLocation_.x_ += location.x_;
		startLocation_.y_ += location.y_;

		endLocation_.x_ += location.x_;
		endLocation_.y_ += location.y_;
	}
}

void MoveCommand::run()
{
	if (actor_)
	{
		Location& location = actor_->getLocation();
		location = endLocation_;
	}
}

void MoveCommand::undo()
{
	if (actor_)
	{
		Location& location = actor_->getLocation();
		location = startLocation_;
	}
}
