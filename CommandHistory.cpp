#include "CommandHistory.h"

CommandHistory::CommandHistory() :
	latestCommandIndex_{-1}
{}

void CommandHistory::record(std::shared_ptr<Command> command)
{
	clearUndoneHistory();
	commands_.push_back(command);
	latestCommandIndex_ = (((int)commands_.size()) - 1);
}

void CommandHistory::undoLastCommand()
{
	if (latestCommandIndex_ >= 0)
	{
		commands_[latestCommandIndex_].get()->undo();
		latestCommandIndex_--;
	}
}

void CommandHistory::redoPreviousComand()
{
	if (latestCommandIndex_ < (((int)commands_.size()) - 1))
	{
		commands_[++latestCommandIndex_].get()->run();
	}
}

void CommandHistory::clearUndoneHistory()
{
	while (commands_.size() > 0 && (((int)commands_.size()) - 1) > latestCommandIndex_)
	{
		commands_.pop_back();
	}
}
