#pragma once

#include <vector>
#include "Command.h"

class CommandHistory
{
public:
	CommandHistory();
	void record(std::shared_ptr<Command> command);
	void undoLastCommand();
	void redoPreviousComand();
protected:
	std::vector<std::shared_ptr<Command>> commands_;
	int latestCommandIndex_;
	void clearUndoneHistory();
};