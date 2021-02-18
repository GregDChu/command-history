#pragma once

#include <iostream>
#include <memory>
#include "Actor.h"
#include "DefaultMessages.h"
#include "Input.h"
#include "InputHandler.h"
#include "Command.h"
#include "CommandHistory.h"

int main()
{
	std::unique_ptr<Actor> player = std::make_unique<Actor>(std::make_unique<Location>());
	std::unique_ptr<InputHandler> inputHandler = std::make_unique<InputHandler>();
	std::unique_ptr<CommandHistory> commandHistory = std::make_unique<CommandHistory>();
	char userInput = 0;
	
	std::cout << DefaultMessages::getCommands() << std::endl;
	while (userInput != Input::QUIT)
	{
		userInput = getchar();
		std::optional<std::shared_ptr<Command>> generatedCommand = inputHandler->handle(userInput);
		if (generatedCommand.has_value())
		{
			std::shared_ptr<Command> command = generatedCommand.value();
			command->setSubject(player.get());
			command->run();
			commandHistory->record(command);
		}
		else if (userInput == Input::UNDO)
		{
			commandHistory->undoLastCommand();
		}
		else if (userInput == Input::REDO)
		{
			commandHistory->redoPreviousComand();
		}
		std::cout << DefaultMessages::formatLocation(player->getLocation()) << std::endl;
	}
	return EXIT_SUCCESS;
}