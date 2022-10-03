#include "Pattern.h"

Pattern::Pattern(const std::string& name, const PatternType type)
{
	_type = type;
	_sprite = Console::Image("assets/images/cards/card_" + name + ".txt");
}
