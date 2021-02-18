#include "Input.h"
#include "InputHandler.h"

std::optional<std::shared_ptr<MoveCommand>> InputHandler::handle(char input)
{
	int xDelta = 0;
	int yDelta = 0;
	switch (input)
	{
	case Input::MOVE_UP:
		yDelta = 1;
		break;
	case Input::MOVE_DOWN:
		yDelta = -1;
		break;
	case Input::MOVE_LEFT:
		xDelta = -1;
		break;
	case Input::MOVE_RIGHT:
		xDelta = 1;
		break;
	default:
		return std::nullopt;
	}
	// TODO: Insert into map for reuse to eliminate duplicates and reduce space complexity
	return std::optional<std::shared_ptr<MoveCommand>>
	{std::make_shared<MoveCommand>(xDelta, yDelta)};
}
