#include "DefaultMessages.h"
#include "Location.h"

const std::string DefaultMessages::getCommands()
{
	return "Commands\n'w' - up\n's' - down\n'd' - right\n'a' - left\n'z' - undo\n'e' - redo\n'q' - quit";
}

const std::string DefaultMessages::formatLocation(const Location& location)
{
	return "Location: " + location.toString();
}
