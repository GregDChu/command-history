#pragma once

#include <memory>
#include <optional>
#include "Actor.h"
#include "MoveCommand.h"
#include "Input.h"

class InputHandler
{
public:
	std::optional<std::shared_ptr<MoveCommand>> handle(char input);
};